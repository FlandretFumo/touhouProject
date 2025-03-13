
#include"Media.h"
// 包含 _bstr_t 用于 COM 错误输出
MediaPlay::MediaPlay(std::string path) {
    mediaThread = new std::thread([this, path] {
        media(path.c_str());
        });
}
std::thread* MediaPlay::getThread() {
    return mediaThread;
}
int MediaPlay::isOK() {
    return WAIT;
}

int MediaPlay::releaseAll() {
    // 假设这些接口已经被正确初始化和使用

// 首先，释放IBasicAudio接口

    if (basicAudio != nullptr) {
        basicAudio->Release();
        basicAudio = nullptr; // 将指针设置为NULL，以避免悬挂指针
    }

    // 接着，释放IMediaSeeking接口
    if (mediaSeek != nullptr) {
        mediaSeek->Release();
        mediaSeek = nullptr;
    }

    // 然后，释放IMediaEvent接口
    if (mediaEvent != nullptr) {
        mediaEvent->Release();
        mediaEvent = nullptr;
    }

    // 接着，释放IMediaControl接口
    if (mediaControl != nullptr) {
        mediaControl->Release();
        mediaControl = nullptr;
    }

    // 最后，释放IGraphBuilder接口
    if (graphBullder != nullptr) {
        graphBullder->Release();
        graphBullder = nullptr;
    }
    return 0;
}
int MediaPlay::play(const std::string path_s_) {
    std::string path = path_s_;
    media(path.c_str());

    return 0;
}
MediaPlay::~MediaPlay() {
    shouldControl.store(CLEAR);

    if (mediaThread->joinable()) {
        mediaThread->join();
        delete mediaThread;
    }
    releaseAll();
}
void MediaPlay::stop() {
    shouldControl.store(STOP);
}
void MediaPlay::run() {
    shouldControl.store(RUN);
    cond = true;
    cv.notify_one();

}
void MediaPlay::run2() {
    shouldControl.store(RUN2);
    cond = true;
    cv.notify_one();

}
void MediaPlay::circulate() {
    shouldCirculate.store(true);
}
void MediaPlay::setVolume(int volume_t) {
    // 输入范围 [0, 100]
         // 输出范围 [-10000, 0]
    int minInput = 0;
    int maxInput = 100;
    int minOutput = -10000;
    int maxOutput = 0;

    // 线性插值公式
    int volume = minOutput + (volume_t - minInput) * (maxOutput - minOutput) / (maxInput - minInput);

    // 存储音量值
    this->volume = volume;
    volumeControl.store(true);
}
void MediaPlay::setBalance(int balance_t) {
    balance_t *= 100;
    balance = balance_t;
    balanceControl.store(true);
}
void MediaPlay::release() {
    shouldControl.store(CLEAR);
}
int MediaPlay::media(const char* filePath) {
    HRESULT result = CoInitialize(NULL);
    if (FAILED(result)) {
        std::cerr << "Failed to initialize COM library: " << _com_error(result).ErrorMessage() << std::endl;
        return 1;
    }

    result = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IFilterGraph, (void**)&graphBullder);
    if (FAILED(result)) {
        std::cerr << "Failed to create Filter Graph: " << _com_error(result).ErrorMessage() << std::endl;
        CoUninitialize();
        return 2;
    }

    result = graphBullder->QueryInterface(IID_IMediaControl, (void**)&mediaControl);
    if (FAILED(result)) {
        std::cerr << "Failed to get IMediaControl interface: " << _com_error(result).ErrorMessage() << std::endl;
        releaseAll();
        return 3;
    }

    result = graphBullder->QueryInterface(IID_IMediaEvent, (void**)&mediaEvent);
    if (FAILED(result)) {
        std::cerr << "Failed to get IMediaEvent interface: " << _com_error(result).ErrorMessage() << std::endl;
        releaseAll();
        return 4;
    }

    result = mediaControl->QueryInterface(IID_IMediaSeeking, (void**)&mediaSeek);
    if (FAILED(result)) {
        std::cerr << "Failed to get IMediaSeeking interface: " << _com_error(result).ErrorMessage() << std::endl;
        releaseAll();
        return 5;
    }

    int len = MultiByteToWideChar(CP_ACP, 0, filePath, -1, NULL, 0);
    wchar_t* path = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, filePath, -1, path, len);

    result = graphBullder->RenderFile(path, NULL);
    delete[] path; // 释放路径内存
    if (FAILED(result)) {
        std::cerr << "Failed to render file: " << _bstr_t(filePath) << std::endl;
        releaseAll();
        return 6;
    }

    result = graphBullder->QueryInterface(IID_IBasicAudio, (void**)&basicAudio);
    if (FAILED(result)) {
        std::cerr << "Failed to get IBasicAudio interface: " << _com_error(result).ErrorMessage() << std::endl;
        releaseAll();
        return 7;
    }

    basicAudio->put_Balance(0);
    basicAudio->put_Volume(0);

    LONGLONG longTemp = 0;
    result = mediaSeek->GetDuration(&longTemp);
    if (FAILED(result)) {
        std::cerr << "Failed to get media duration: " << _com_error(result).ErrorMessage() << std::endl;
        return -1;
    }
    else {
        double durationInSeconds = double(longTemp) / 10000000.0;
        // std::cout << "Duration: " << longTemp << "ns (" << durationInSeconds << "s)" << std::endl;
    }

    if (FAILED(result)) {
        std::cerr << "Failed to run media: " << _com_error(result).ErrorMessage() << std::endl;
        releaseAll();
        return 8;
    }
    long log = 0;
    long long location = 0;
    while (true) {
        if (shouldControl.load() == STOP || shouldControl.load() == WAIT) {
            mediaControl->Stop();
            shouldControl.store(WAIT);
            std::unique_lock<std::mutex> lock(mut);
            cv.wait(lock, [this] {return cond;  });
            cond = false;
        }
        else {
            if (shouldControl.load() == CLEAR) {
                shouldCirculate.store(false);
                releaseAll();
                break;
            }
            if (shouldControl.load() == RUN) {
                mediaControl->Run();
            }
            if (volumeControl.load()) {
                if (basicAudio != nullptr) {
                    basicAudio->put_Volume(volume);
                    volumeControl.store(false);
                    continue;
                }
            }
            if (balanceControl.load()) {
                    if (basicAudio != nullptr) {
                        basicAudio->put_Balance(balance);
                    }
                    balanceControl.store(false);
                    continue;
                }
            if (mediaEvent != nullptr) {
                    result = mediaEvent->WaitForCompletion(10, &log); // 使用较短的超时时间来定期检查停止标志
            }
            if (SUCCEEDED(result)) {
                if (shouldCirculate.load()) {
                    mediaSeek->SetPositions(&location, AM_SEEKING_AbsolutePositioning | AM_SEEKING_SeekToKeyFrame, nullptr, AM_SEEKING_NoPositioning);
                    continue;
                }
                else {
                        shouldControl.store(WAIT);
                        continue;
                }
            }
        }
        if (shouldControl.load() == RUN2) {
            mediaSeek->SetPositions(&location, AM_SEEKING_AbsolutePositioning | AM_SEEKING_SeekToKeyFrame, nullptr, AM_SEEKING_NoPositioning);
            basicAudio->put_Volume(volume);
            mediaControl->Run();
            shouldControl.store(114514);
            continue;
        }
    }
    return 0;
}
int MediaPlay::isWait() {
    return shouldControl.load();
}
#include "MediaManager.h"
#include <iostream>
#include <thread>
#include <chrono>

MediaManager::MediaManager(const std::string& audioPath, int count)
    : audioPath_(audioPath), mediaCount_(count), player(true) {
    initializeMediaPlays();
}

MediaManager::~MediaManager() {
    for (auto& media : mediaPlays_) {
        delete media;
    }
}

bool MediaManager::play() {
    player = true;
    // 尽量找到一个可以播放的，如果没有就返回
    for (int i = 0; i < 10 && player; i++) {
        for (auto& media : mediaPlays_) {
            if (media->isWait() == media->isOK()) {
                media->run2();
                player = false;
                return true;
            }
        }
    }
    return false;
}

void MediaManager::initializeMediaPlays() {
    for (int i = 0; i < mediaCount_; ++i) {
        MediaPlay* music = new (std::nothrow) MediaPlay(audioPath_);
        if (music) {
            mediaPlays_.push_back(music);
        }
        else {
            std::cerr << "Failed to allocate memory for MediaPlay object." << std::endl;
        }
    }
}
#include "GameTick.h"

GameTick::GameTick() {
    _thread = new std::thread([this] {
        run();
        });
}

GameTick::~GameTick() {
    if (_thread->joinable()) {
        _thread->join();
    }
    delete _thread; // 清理线程指针
}

void GameTick::run() {
    const float tickDuration = 0.05f; // 每个tick的时间（秒）
    const int nanosecondsPerSecond = 1'000'000'000; // 1秒等于多少纳秒
    tickInNanoseconds = nanosecondsPerSecond * tickDuration; // 每个tick的纳秒数

    while (true) {

        tickTime();
        auto it = listAtomic.begin();
        while (it != listAtomic.end()) {
            std::lock_guard<std::mutex> lock(mut); // 使用RAII方式管理锁
            (*it)->tick++;
            if ((*it)->tick == (*it)->tagete) {
                if ((*it)->ato) {
                    (*it)->ato->store(true);
                }
                if ((*it)->boo) {
                    *(*it)->boo = true;
                }
                delete* it;
                it = listAtomic.erase(it); // 使用迭代器安全地删除元素
            }
            else {
                ++it;
            }
        }
    }
}

void GameTick::tickTime() {
    std::this_thread::sleep_for(std::chrono::nanoseconds(tickInNanoseconds));
}
void GameTick::addBool(bool * ato, int tick) {
    if (ato != nullptr) {
        std::lock_guard<std::mutex> lock(mut);
        objStruct* obj = new objStruct();
        obj->boo = ato;
        obj->tagete = tick;
        listAtomic.push_back(obj);
    }
}
void GameTick::addAtomic(std::atomic<bool>* ato, int tick) {
    if (ato != nullptr) {
        std::lock_guard<std::mutex> lock(mut);
        objStruct* obj = new objStruct();
        obj->ato = ato;
        obj->tagete = tick;
        listAtomic.push_back(obj);
    }
}
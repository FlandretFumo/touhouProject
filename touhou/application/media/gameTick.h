
#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>

class GameTick {
public:
    GameTick();
    ~GameTick();
    void addAtomic(std::atomic<bool>* ato, int tick);
    void addBool(bool* ato, int tick);
private:
    struct objStruct {
        int tagete;
        std::atomic<bool>* ato;
        bool* boo;
        int tick;
    };

    std::vector<objStruct*> listAtomic;
    std::mutex mut;
    std::thread* _thread;
    int tick = 0; // ³õÊ¼»¯tickÎª0
    int time = 0;
    int tickInNanoseconds;
    void run();
    void tickTime();
};
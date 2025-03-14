#pragma once
#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <string>
#include <vector>
#include "Media.h"

class MediaManager {
public:
    MediaManager(const std::string& audioPath, int count);
    ~MediaManager();
    bool play();

private:
    void initializeMediaPlays();

    std::string audioPath_;
    int mediaCount_;
    std::vector<MediaPlay*> mediaPlays_;
    bool player;
};

#endif // MEDIAMANAGER_H
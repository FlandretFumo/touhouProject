#pragma once
#include<Windows.h>
#include<iostream>
#include<dshow.h>
#include<thread>
#include<string>
#include<atomic>
#include <chrono>
#include <comdef.h>
#include<condition_variable>
#include<mutex>
#define STOP 0
#define RUN 1
#define RUN2 8
#define CLEAR 2
#define VOLUME 4
#define BALANCE 5
#define CIRCULATE 6
#define WAIT 6

#define MAX_VOLUME 10000
#define MIN_VOLUME -10000
#define MAX_FALANCE 10000
#define MIN_FALANCE -10000

class MediaPlay {
public:
	MediaPlay(std::string path);
	~MediaPlay();
	int isOK();
	std::thread* getThread();
	int play(const std::string path_s);
	void stop();
	void run();
	void run2();
	void circulate();
	void setVolume(int velume_t);
	void setBalance(int banlac_t);
	void release();
	int isWait();
private:
	int releaseAll();
	int volume = 0;
	int balance = 0;
	std::atomic<int> shouldControl = { 0 };
	std::atomic<bool> volumeControl = false;
	std::atomic<bool> balanceControl = false;
	std::atomic<bool> shouldCirculate = false;
	bool cond = false;
	std::condition_variable cv;
	std::mutex mut;
	int media(const char* filePath);
	std::thread* mediaThread = nullptr;
	IGraphBuilder* graphBullder = NULL;
	IMediaControl* mediaControl = NULL;
	IMediaEvent* mediaEvent = NULL;
	IMediaSeeking* mediaSeek = NULL;
	IBasicAudio* basicAudio = NULL;
};
#pragma once
#include<thread>
#include<iostream>
#include<vector>
#include<atomic>
class ThreadManager {
public:
	ThreadManager();
	~ThreadManager();
	void addThread(std::thread* );
private:
	void release();
	std::vector<std::thread*> threads;
	std::atomic<bool> off;
	std::thread* thread;
};
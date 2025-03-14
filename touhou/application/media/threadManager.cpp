#include"threadManager.h"
ThreadManager::ThreadManager() {
	thread = new std::thread([this] {
		ThreadManager::release();
	});
}
ThreadManager::~ThreadManager(){

}
void ThreadManager::addThread(std::thread * th) {
	off.store(false);
	if (th!=nullptr) {
		threads.emplace_back(th);
	}
	off.store(true);
}
void ThreadManager::release() {
	while (true) {
		if (off.load()) {
			for (auto i = 0; i < threads.size();i++) {
				if (off.load()) {
					if (threads.at(i)->joinable()) {
						threads.at(i)->join();
					}
					delete threads.at(i);
					threads.erase(threads.begin() + i);
				}
				else {
					break;
				}
				
			}
		}
	}
}
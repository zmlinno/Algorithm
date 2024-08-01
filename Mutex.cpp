#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>

// 共享数据
int sharedCounter = 0;
// 互斥锁
std::mutex mtx;

void incrementCounter(int id, int numIterations) {
    for (int i = 0; i < numIterations; ++i) {
        // 加锁
        std::lock_guard<std::mutex> lock(mtx);
        ++sharedCounter;
        std::cout << "Thread " << id << " incremented counter to " << sharedCounter << std::endl;
        // 锁会在lock_guard对象析构时自动释放
    }
}

int main() {
    const int numThreads = 5;
    const int numIterations = 10;
    std::thread threads[numThreads];

    // 创建并启动线程
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(incrementCounter, i, numIterations);
    }

    // 等待所有线程完成
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    std::cout << "Final counter value: " << sharedCounter << std::endl;
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>

// ��������
int sharedCounter = 0;
// ������
std::mutex mtx;

void incrementCounter(int id, int numIterations) {
    for (int i = 0; i < numIterations; ++i) {
        // ����
        std::lock_guard<std::mutex> lock(mtx);
        ++sharedCounter;
        std::cout << "Thread " << id << " incremented counter to " << sharedCounter << std::endl;
        // ������lock_guard��������ʱ�Զ��ͷ�
    }
}

int main() {
    const int numThreads = 5;
    const int numIterations = 10;
    std::thread threads[numThreads];

    // �����������߳�
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(incrementCounter, i, numIterations);
    }

    // �ȴ������߳����
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    std::cout << "Final counter value: " << sharedCounter << std::endl;
    return 0;
}

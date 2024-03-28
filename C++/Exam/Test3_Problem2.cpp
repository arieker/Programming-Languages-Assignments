#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void countByOne() {
    for (int i = 1; i <= 10000; ++i) {
        mtx.lock();
        cout << "1:" << i << ":";
        mtx.unlock();
    }
}

void countByTwo() {
    for (int i = 2; i <= 20000; i += 2) {
        mtx.lock();
        cout << "2:" << i << ":";
        mtx.unlock();
    }
}

void countBySeven() {
    for (int i = 7; i <= 70000; i += 7) {
        mtx.lock();
        cout << "3:" << i << ":";
        mtx.unlock();
    }
}

int main() {
    thread t1(countByOne);
    thread t2(countByTwo);
    thread t3(countBySeven);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
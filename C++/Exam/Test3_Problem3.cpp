#include <iostream>
#include <string>
#include <mutex>
using namespace std;

class MyPrinter {
private:
    static MyPrinter* instance;
    static mutex mtx;
    MyPrinter() {}

public:
    static MyPrinter* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new MyPrinter();
            }
        }
        return instance;
    }

    void print(const string& data) {
        cout << "Printing: " << data << endl;
    }
};

MyPrinter* MyPrinter::instance = nullptr;
mutex MyPrinter::mtx;

int main() {
    MyPrinter* p1 = MyPrinter::getInstance();
    MyPrinter* p2 = MyPrinter::getInstance();
    MyPrinter* p3 = MyPrinter::getInstance();

    p1->print("Document 1");
    p2->print("Document 2");
    p3->print("Document 3");

    return 0;
}
#include <iostream>
using namespace std;

class Person {
public:
    virtual void sayIt() = 0;
    void doIt() {
        cout << "Doing it..." << endl;
    }
};

class PsychologyMajor : public Person {
public:
    void sayIt() override {
        cout << "PsychologyMajor output" << endl;
    }
};

class ComputerScienceMajor : public Person {
public:
    void sayIt() override {
        cout << "ComputerScienceMajor output" << endl;
    }
};

class Barista : public Person {
public:
    void sayIt() override {
        cout << "Barista output" << endl;
    }
};

int main() {
    PsychologyMajor a;
    ComputerScienceMajor b;
    Barista c;
    Person *f;

    f = &a;
    f->sayIt();
    f = &b;
    f->sayIt();
    f = &c;
    f->sayIt();

    return 0;
}
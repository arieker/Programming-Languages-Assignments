#include <iostream>
#include <string>
using namespace std;

class student {
private:
    int admno;
    char sname[20];
    float eng, math, science;
    float total;

    float ctotal() {
        total = eng + math + science;
        return total;
    }

public:
    void Takedata() {
        cout << "Enter admission number: ";
        cin >> admno;
        cout << "Enter student name: ";
        cin >> sname;
        cout << "Enter marks (English, Math, Science): ";
        cin >> eng >> math >> science;
        ctotal(); 
    }

    void Showdata() {
        cout << "Admission Number: " << admno << endl;
        cout << "Student Name: " << sname << endl;
        cout << "Marks: English = " << eng << ", Math = " << math << ", Science = " << science << endl;
        cout << "Total Marks: " << total << endl;
    }
};

class batsman {
private:
    int bcode;
    char bname[20];
    int innings, notout, runs;
    float batavg;

    void calcavg() {
        if (innings - notout != 0) {
            batavg = (float)runs / (innings - notout);
        } else {
            batavg = 0; // Handle division by zero
        }
    }

public:
    void readdata() {
        cout << "Enter batsman code: ";
        cin >> bcode;
        cout << "Enter batsman name: ";
        cin >> bname;
        cout << "Enter innings, notout, runs: ";
        cin >> innings >> notout >> runs;
        calcavg();
    }

    void displaydata() {
        cout << "Batsman Code: " << bcode << endl;
        cout << "Batsman Name: " << bname << endl;
        cout << "Innings: " << innings << ", Not Out: " << notout << ", Runs: " << runs << endl;
        cout << "Batting Average: " << batavg << endl;
    }
};

class TEST {
private:
    int TestCode;
    string Description;
    int NoCandidate;
    int CenterReqd; 

    int CALCNTR() {
        CenterReqd = NoCandidate / 100 + 1;
        return CenterReqd;
    }

public:
    void SCHEDULE() {
        cout << "Enter Test Code: ";
        cin >> TestCode;
        cout << "Enter Description: "; 
        cin >> Description;
        cout << "Enter Number of Candidates: ";
        cin >> NoCandidate;
        CALCNTR();
    }

    void DISPTEST() {
        cout << "Test Code: " << TestCode << endl;
        cout << "Description: " << Description << endl;
        cout << "Number of Candidates: " << NoCandidate << endl;
        cout << "Centers Required: " << CenterReqd << endl;
    }
};

class flight {
private:
    int FlightNo;
    string Destination;
    float Distance, Fuel; 

    void CALFUEL() {
        if (Distance <= 1000) {
            Fuel = 500;
        } else if (Distance <= 2000) {
            Fuel = 1100;
        } else {
            Fuel = 2200;
        }
    }

public:
    void FEEDINFO() {
        cout << "Enter Flight Number: ";
        cin >> FlightNo;
        cout << "Enter Destination: ";
        cin >> Destination;
        cout << "Enter Distance: ";
        cin >> Distance;
        CALFUEL();
    }

    void SHOWINFO() {
        cout << "Flight Number: " << FlightNo << endl;
        cout << "Destination: " << Destination << endl;
        cout << "Distance: " << Distance << endl;
        cout << "Fuel Required: " << Fuel << endl;
    }
};

class BOOK {
private:
    int BOOK_NO;
    char BOOKTITLE[20];
    float PRICE;

    float TOTAL_COST(int N) {
        return PRICE * N;
    }

public:
    void INPUT() {
        cout << "Enter Book Number: ";
        cin >> BOOK_NO;
        cout << "Enter Book Title: ";
        cin >> BOOKTITLE;
        cout << "Enter Price: ";
        cin >> PRICE;
    }

    void PURCHASE() {
        int N;
        cout << "Enter number of copies: ";
        cin >> N;
        cout << "Total cost: " << TOTAL_COST(N) << endl;
    }
};

class REPORT {
private:
    int adno;
    char name[20];
    float marks[5];
    float average;

    void GETAVG() {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        average = sum / 5.0;
    }

public:
    void READINFO() {
        cout << "Enter Admission Number: ";
        cin >> adno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks (5 subjects): ";
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
        GETAVG();
    }

    void DISPLAYINFO() {
        cout << "Admission Number: " << adno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
         }
         cout << endl;
         cout << "Average: " << average << endl;
    }
};

class Rectangle {
private:
    float length, width;

public:
    void setlength(float l) { length = l; }
    void setwidth(float w) { width = w; }
    float perimeter() { return 2 * (length + width); }
    float area() { return length * width; }
    void show() { 
        cout << "Length: " << length << ", Width: " << width << endl; 
    }
    int sameArea(Rectangle rect) {
        return (length * width == rect.length * rect.width);
    }
};

class complex {
private:
    float real, imag;

public:
    void set(float r, float i) { 
        real = r; 
        imag = i; 
    }

    void disp() {
        cout << real;
        if (imag >= 0) {
            cout << "+" << imag << "i" << endl;
        } else {
            cout << imag << "i" << endl; // Displaying the negative imaginary part
        }
    }

    complex sum(complex c) {
        complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
};

class Distance {
private:
    int feet;
    float inches;

public:
    void set(int f, float i) { 
        feet = f; 
        inches = i; 
    }

    void disp() {
        cout << feet << " feet, " << inches << " inches" << endl;
    }

    Distance add(Distance d) {
        Distance result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;

        // Adjust if inches exceed 12 
        if (result.inches >= 12) {
            result.feet++;
            result.inches -= 12;
        }
        return result;
    }
};

class time {
private:
    int hours, minutes; 

public:
    void settime(int h, int m) {
        hours = h;
        minutes = m;
    }

    void showtime() {
        cout << hours << ":" << minutes << endl;
    }

    time sum(time t) {
        time result;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours + result.minutes / 60;
        result.minutes %= 60;
        return result;
    }
};
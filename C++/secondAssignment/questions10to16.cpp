#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class EMPLOYEE {
    int ENO;
    char ENAME[10];
public:
    void GETIT() {
        cin >> ENO;
        cin.ignore();
        cin.getline(ENAME, 10);
    }
    void SHOWIT() {
        cout << ENO << " " << ENAME << endl;
    }
};

class Computer {
    char chiptype[10];
    int speed;
public:
    void getdetails() {
        cin.ignore();
        cin.getline(chiptype, 10);
        cin >> speed;
    }
    void showdetails() {
        cout << "Chip " << chiptype << " Speed = " << speed << endl;
    }
};

class Student {
    char S_Admno[10];
    char S_Name[30];
    int Percentage;
public:
    void EnterData() {
        cin.ignore();
        cin.getline(S_Admno, 10);
        cin.getline(S_Name, 30);
        cin >> Percentage;
    }
    void DisplayData() {
        cout << setw(12) << S_Admno << setw(32) << S_Name << setw(3) << Percentage << endl;
    }
    int ReturnPercentage() {
        return Percentage;
    }
};

int Countrec() {
    fstream File;
    File.open("EMP.DAT", ios::binary | ios::in);
    File.seekg(0, ios::end);
    int Bytes = File.tellg();
    int Count = Bytes / sizeof(EMPLOYEE);
    File.close();
    return Count;
}

void ReadFromFileAndDisplay() {
    ifstream file("SHIP.DAT", ios::binary);
    if (file.is_open()) {
        Computer obj;
        int count = 0;
        while (file.read((char*)&obj, sizeof(obj))) {
            obj.showdetails();
            count++;
        }
        cout << "Number of records: " << count << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void DisplayAbove75() {
    ifstream file("STUDENT.DAT", ios::binary);
    if (file.is_open()) {
        Student obj;
        while (file.read((char*)&obj, sizeof(obj))) {
            if (obj.ReturnPercentage() > 75) {
                obj.DisplayData();
            }
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void AddNewObjects() {
    ofstream file("STUDENT.DAT", ios::binary | ios::app);
    if (file.is_open()) {
        Student obj;
        obj.EnterData();
        file.write((char*)&obj, sizeof(obj));
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

class Item {
    int Ino;
    char Item[20];
public:
    void Search(int RecNo);
    void Modify(int RecNo);
};

void Item::Search(int RecNo) {
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in);
    File.seekg(RecNo * sizeof(Item));
    File.read((char*)this, sizeof(Item));
    cout << Ino << " ==> " << Item << endl;
    File.close();
}

void Item::Modify(int RecNo) {
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in | ios::out);
    File.seekp(RecNo * sizeof(Item));
    cin >> Ino;
    cin.ignore();
    cin.getline(Item, 20);
    File.write((char*)this, sizeof(Item));
    File.close();
}

int main() {
    return 0;
}

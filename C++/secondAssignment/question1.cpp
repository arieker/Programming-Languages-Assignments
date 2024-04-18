#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("NOTES.TXT");
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 1; i <= 100; ++i)
    {
        file << i << endl;
    }
    file.close();

    cout << "Numbers from 1 to 100 have been written to NOTES.TXT" << endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int countAlphabets(const string& filename) {
    ifstream file(filename);
    char ch;
    int count = 0;

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    while (file.get(ch)) {
        if (isalpha(ch)) {
            ++count;
        }
    }

    file.close();
    return count;
}

int countBlanks(const string& filename) {
    ifstream file(filename);
    char ch;
    int count = 0;

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    while (file.get(ch)) {
        if (ch == ' ') {
            ++count;
        }
    }

    file.close();
    return count;
}

int countWords(const string& filename) {
    ifstream file(filename);
    string word;
    int count = 0;

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    while (file >> word) {
        ++count;
    }

    file.close();
    return count;
}

int countWordOccurrences(const string& filename, const string& targetWord) {
    ifstream file(filename);
    string word;
    int count = 0;

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    while (file >> word) {
        if (word == targetWord) {
            ++count;
        }
    }

    file.close();
    return count;
}

int countLinesNotStartingWithA(const string& filename) {
    ifstream file(filename);
    string line;
    int count = 0;

    if (!file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return -1;
    }

    while (getline(file, line)) {
        if (!line.empty() && toupper(line[0]) != 'A') {
            ++count;
        }
    }

    file.close();
    return count;
}

void copyUpper(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cout << "Error opening input file " << inputFile << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Error opening output file " << outputFile << endl;
        inFile.close();
        return;
    }

    string word;
    while (inFile >> word) {
        for (char& ch : word) {
            ch = toupper(ch);
        }
        outFile << word << " ";
    }

    inFile.close();
    outFile.close();
}

void vowelWords(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cout << "Error opening input file " << inputFile << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Error opening output file " << outputFile << endl;
        inFile.close();
        return;
    }

    string word;
    while (inFile >> word) {
        if (islower(word[0]) && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) {
            outFile << word << " ";
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    ofstream outFile("OUT.TXT");
    if (outFile.is_open()) {
        string str = "Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
        outFile << str;
        outFile.close();
    } else {
        cout << "Error creating file OUT.TXT" << endl;
        return 1;
    }

    cout << "Number of alphabets in OUT.TXT: " << countAlphabets("OUT.TXT") << endl;

    cout << "Number of blanks in OUT.TXT: " << countBlanks("OUT.TXT") << endl;

    cout << "Number of words in OUT.TXT: " << countWords("OUT.TXT") << endl;

    cout << "Number of occurrences of 'the' in STORY.TXT: " << countWordOccurrences("STORY.TXT", "the") << endl;

    cout << "Number of lines not starting with 'A' in STORY.TXT: " << countLinesNotStartingWithA("STORY.TXT") << endl;

    copyUpper("FIRST.TXT", "SECOND.TXT");

    vowelWords("FIRST.TXT", "SECOND.TXT");

    return 0;
}
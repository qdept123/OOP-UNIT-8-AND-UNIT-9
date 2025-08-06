#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string text;

    // ======== 1. Writing to the file using ofstream::open() ========
    ofstream outFile; // declare without opening
    outFile.open(filename); // open manually
    if (!outFile.is_open()) {
        cerr << "Failed to open file for writing.\n";
        return 1;
    }

    outFile << "Line 1: This file was opened using open().\n";
    outFile << "Line 2: It will be closed using close().\n";
    outFile.close(); // manually closing the file
    cout << "Data written to file and file closed using close().\n\n";

    // ======== 2. Reading from the file using ifstream::open() ========
    ifstream inFile;
    inFile.open(filename); // manually open file for reading
    if (!inFile.is_open()) {
        cerr << "Failed to open file for reading.\n";
        return 1;
    }

    cout << "Reading content of the file:\n";
    while (getline(inFile, text)) {
        cout << text << endl;
    }
    inFile.close(); // manually close after reading

    return 0;
}

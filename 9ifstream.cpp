#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "sample.txt";

    // ======== 1. Writing to a file using ofstream ========
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    outFile << "Hello, this is line 1.\n";
    outFile << "This is line 2.\n";
    outFile << "End of file content.\n";
    outFile.close();
    cout << "Data written to file using ofstream.\n\n";

    // ======== 2. Reading from the file using ifstream ========
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "Reading file using ifstream:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    // ======== 3. Using fstream for read/write ========
    fstream file(filename, ios::in | ios::out | ios::app);  // open for reading and appending
    if (!file) {
        cerr << "Error opening file using fstream!" << endl;
        return 1;
    }

    file << "This line was added using fstream.\n";
    file.close();

    // Reopen to confirm the addition
    ifstream checkFile(filename);
    cout << "\nFinal content of the file:\n";
    while (getline(checkFile, line)) {
        cout << line << endl;
    }
    checkFile.close();

    return 0;
}

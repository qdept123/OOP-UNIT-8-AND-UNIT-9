#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class to demonstrate binary write() and read()
class Student {
public:
    int id;
    char name[30];

    void input() {
        cout << "\nEnter Student ID: ";
        cin >> id;
        cin.ignore();  // Clear newline from buffer
        cout << "Enter Student Name: ";
        cin.getline(name, 30);
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    string textFilename = "textfile.txt";
    string binaryFilename = "student.dat";

    // ===============================
    // 1. Write text to file using put()
    // ===============================
    ofstream textOut(textFilename);
    if (!textOut) {
        cerr << "Error opening text file for writing.\n";
        return 1;
    }

    string message = "Hello from put() demo!";
    for (char c : message) {
        textOut.put(c);  // writing character by character
    }
    textOut.close();
    cout << "\nText written to file using put().\n";

    // ===============================
    // 2. Read text using get()
    // ===============================
    ifstream textIn(textFilename);
    if (!textIn) {
        cerr << "Error opening text file for reading.\n";
        return 1;
    }

    char ch;
    cout << "Reading text file using get():\n";
    while (textIn.get(ch)) {
        cout << ch;
    }
    cout << endl;
    textIn.close();

    // ===============================
    // 3. Write object to binary file using write()
    // ===============================
    Student s1;
    s1.input();

    ofstream binOut(binaryFilename, ios::binary);
    if (!binOut) {
        cerr << "Error opening binary file for writing.\n";
        return 1;
    }

    binOut.write(reinterpret_cast<char*>(&s1), sizeof(s1));
    binOut.close();
    cout << "\nStudent data written to binary file using write().\n";

    // ===============================
    // 4. Read object from binary file using read()
    // ===============================
    Student s2;
    ifstream binIn(binaryFilename, ios::binary);
    if (!binIn) {
        cerr << "Error opening binary file for reading.\n";
        return 1;
    }

    binIn.read(reinterpret_cast<char*>(&s2), sizeof(s2));
    binIn.close();

    cout << "\nStudent data read from file using read():\n";
    s2.display();

    return 0;
}

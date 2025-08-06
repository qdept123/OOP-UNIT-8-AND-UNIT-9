#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename = "pointer_demo.txt";

    // Step 1: Create and write data to file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error creating file.\n";
        return 1;
    }

    outFile << "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26 characters
    cout << "Written 'A' to 'Z' to the file.\n";
    cout << "Current write pointer (tellp): " << outFile.tellp() << endl;
    outFile.close();

    // Step 2: Read and use file access pointers
    fstream file(filename, ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }

    // tellg() - current position of get pointer
    cout << "\nInitial get pointer position (tellg): " << file.tellg() << endl;

    // seekg(offset, direction)
    file.seekg(5, ios::beg); // Move 5 characters from beginning
    cout << "Moved get pointer to position 5 from beginning.\n";
    cout << "Current get pointer position: " << file.tellg() << endl;

    char ch;
    file.get(ch);  // Read the character at position 5
    cout << "Character at position 5: " << ch << endl;

    // seekg with ios::cur
    file.seekg(2, ios::cur);  // Move 2 characters ahead from current position
    file.get(ch);
    cout << "Character after moving 2 positions from current: " << ch << endl;

    // seekg with ios::end
    file.seekg(-1, ios::end);  // Move to last character
    file.get(ch);
    cout << "Last character in file (seekg from ios::end): " << ch << endl;

    // Step 3: Demonstrate seekp (put pointer) — overwrite character
    file.seekp(0, ios::beg);  // Move put pointer to start
    cout << "\nInitial put pointer position (tellp): " << file.tellp() << endl;
    file.put('Z');            // Overwrite 'A' with 'Z'
    cout << "Overwritten first character with 'Z'\n";
    cout << "Current put pointer position (tellp): " << file.tellp() << endl;

    file.seekp(-1, ios::end); // Move to last character
    file.put('X');            // Overwrite last character
    cout << "Overwritten last character with 'X'\n";

    file.close();

    // Step 4: Display final file content
    ifstream finalIn(filename);
    cout << "\nFinal file content:\n";
    string line;
    getline(finalIn, line);
    cout << line << endl;
    finalIn.close();

    return 0;
}

#include <iostream>
using namespace std;

// Class Template
template <class T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) {
        first = a;
        second = b;
    }

    T getMax() {
        return (first > second) ? first : second;
    }

    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    Pair<int> intPair(10, 20);
    intPair.display();
    cout << "Max: " << intPair.getMax() << endl;

    Pair<double> doublePair(3.5, 2.1);
    doublePair.display();
    cout << "Max: " << doublePair.getMax() << endl;

    Pair<char> charPair('x', 'y');
    charPair.display();
    cout << "Max: " << charPair.getMax() << endl;

    return 0;
}

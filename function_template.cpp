#include <iostream>
using namespace std;

// Function Template
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of 10 and 20 is: " << findMax(10, 20) << endl;
    cout << "Max of 3.14 and 2.71 is: " << findMax(3.14, 2.71) << endl;
    cout << "Max of 'a' and 'z' is: " << findMax('a', 'z') << endl;

    return 0;
}

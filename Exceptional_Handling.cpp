#include <iostream>
using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw "Division by zero error!";
    }
    return numerator / denominator;
}

int main() {
    double a, b;

    cout << "Enter numerator: ";
    cin >> a;
    cout << "Enter denominator: ";
    cin >> b;

    try {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }

    return 0;
}

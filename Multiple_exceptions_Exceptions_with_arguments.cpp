#include <iostream>
using namespace std;

void MultipleException(int x)
{
    try
    {
        if (x > 0)
            throw x; // throwing integer as exception
        else
            throw 'x'; // throwing character as an exception
    }
    catch (int x)
    {
        cout << "Caught Integer: " << x << endl;
    }
    catch (char x)
    {
        cout << "Caught Character: " << x << endl;
    }
}

int main()
{
    cout << "Multiple Exceptions Testing" << endl;
    MultipleException(10);
    MultipleException(0);
    return 0;
}

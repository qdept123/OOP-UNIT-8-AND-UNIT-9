#include <iostream>
using namespace std;
template <typename T>
class base
{
protected:
T x;
T y;
};
template <typename T>
class derived : public base<T>
{
public:
derived(T a, T b)
{
this->x = a;
this->y = b;
}
int f() { return this->x * this->y; }
};
int main(void)
{
derived<int> d(35, 45);
cout << d.f() << endl;
}
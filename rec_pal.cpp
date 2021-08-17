
#include <iostream>

using namespace std;
int sum(int n);

int main()
{
    cout << sum(12345);
    return 0;
}

int sum(int n)
{
    if (n <= 0)
        return n;
    return (n % 10) + sum(n / 10);
}
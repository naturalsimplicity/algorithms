#include <string>
#include <iostream>
using namespace std;

int main()
{
    int x, steps;
    cin >> x;

    steps = x / 5;
    if (steps * 5 < x) {
        steps += 1;
    }
    cout << steps << '\n';

    return 0;
}
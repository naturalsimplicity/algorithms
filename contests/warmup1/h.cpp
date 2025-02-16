#include <iostream>
using namespace std;

int main() 
{
    int i, j;
    for (int k = 0; k < 25; ++k) {
        int val;
        cin >> val;
        if (val == 1) {
            i = k / 5;
            j = k % 5;
        }
    }
    cout << abs(i - 2) + abs(j - 2) << endl;
    return 0;
}
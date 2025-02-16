#include <iostream>
using namespace std;

int main() 
{
    int p;
    cin >> p;
    if (p % 2 == 0 && p > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// LCM - least common multiple
// GCD - greatest common divisor

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int32_t l, r;
        cin >> l >> r;

        if (l <= r / 2) { // safe check of l * 2 <= r
            cout << l << ' ' << l*2 << '\n';
        } else {
            cout << -1 << ' ' << -1 << '\n';
        }
    }
    
    return 0;
}

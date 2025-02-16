#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j;
        int x1, y1, x2, y2;
        cin >> n >> m >> i >> j;

        if (i <= n / 2) {
            x1 = n;
            x2 = 1;
        } else {
            x1 = 1;
            x2 = n;
        }

        if (j <= m / 2) {
            y1 = m;
            y2 = 1;
        } else {
            y1 = 1;
            y2 = m;
        }

        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';

        // x x x x
        // x x x x
        // x x x x

    }

    return 0;
}
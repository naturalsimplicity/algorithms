#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> array2d_t;

int main() {
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;
    int x_, y_, z_;
    for (int i = 0; i < n; ++i) {
        cin >> x_ >> y_ >> z_;
        x += x_;
        y += y_;
        z += z_;
    }

    if (x == 0 && y == 0 && z == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    };
    cout << '\n';

    return 0;
}
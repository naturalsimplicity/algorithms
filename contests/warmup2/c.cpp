#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    string stones;
    cin >> n >> stones;

    int stones_to_remove = 0;
    for (int i = 1; i < n; ++i) {
        if (stones[i] == stones[i-1]) {
            stones_to_remove += 1;
        }
    }
    cout << stones_to_remove << '\n';

    return 0;
}
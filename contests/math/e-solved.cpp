#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int tmp = n;
    int pos = 2 * n;
    while (tmp--) {
        cout << pos << ' ';
        pos += 2;
    }
    cout << endl;
}
 
int main()
{
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
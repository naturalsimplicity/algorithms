#include <iostream>
#include <string>

using namespace std;

// TESTS:
// qwqwq, a1=qw, a2=q, k=1, YES
// dokidokiliteratureclub, a1=dokidokiliteratureclub, k=0, YES
// abqwertyba, a1=a, a2=b, a3=qwerty, k=2, YES

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (s.size() < 2 * k + 1) {
            cout << "NO" << '\n';
            continue;
        }
        int symmetric_cnt = s.size() / 2;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size()-i-1]) {
                symmetric_cnt = i;
                break;
            }
        }
        if (symmetric_cnt > k || symmetric_cnt == k && s.size() - symmetric_cnt * 2 > 0 || k == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
    vector<vector<int>> cnt(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        is_palindrome[i][i] = true;
        cnt[i][i] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            is_palindrome[i][i + 1] = true;
            cnt[i][i + 1] = 3;
        } else {
            cnt[i][i + 1] = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            if (s[l] == s[r] && is_palindrome[l + 1][r - 1]) {
                is_palindrome[l][r] = true;
            }
            cnt[l][r] = cnt[l][r - 1] + cnt[l + 1][r] - cnt[l + 1][r - 1];
            if (is_palindrome[l][r]) {
                cnt[l][r] += 1;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cnt[l - 1][r - 1] << '\n';
    }

    return 0;
}

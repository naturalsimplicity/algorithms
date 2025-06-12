#include <iostream>
#include <vector>

using namespace std;

int MinimizeSum(vector<int>& v, int s) {
    int n = v.size();
    int total_ones = 0;
    for (int num : v) {
        if (num == 1) {
            ++total_ones;
        }
    }
    if (total_ones < s) {
        return -1;
    }
    if (total_ones == s) {
        return 0;
    }

    int left = 0, right = 0;
    int current_ones = 0;
    int min_operations = n;

    while (right < n) {
        if (v[right] == 1) {
            ++current_ones;
        }
        while (current_ones > s) {
            if (v[left] == 1) {
                --current_ones;
            }
            ++left;
        }
        if (current_ones == s) {
            int operations = (left) + (n - 1 - right);
            if (operations < min_operations) {
                min_operations = operations;
            }
        }
        ++right;
    }

    return min_operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cout << MinimizeSum(v, s) << '\n';
    }
    return 0;
}

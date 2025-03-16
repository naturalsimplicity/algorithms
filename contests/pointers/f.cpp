#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

vector<int32_t> MaxShootCount(vector<vector<int32_t>>& droids, int32_t n, int32_t m, int32_t k) {
    int32_t left = 0;
    vector<int32_t> max_shoots(m);
    vector<int32_t> current_shoots(m);
    int64_t shoots_cnt = 0;
    int32_t max_length = 0; 

    for (int32_t right = 0; right < n; ++right) {
        for (int32_t i = 0; i < m; ++i) {
            if (droids[right][i] > current_shoots[i]) {
                shoots_cnt += droids[right][i] - current_shoots[i];
                current_shoots[i] = droids[right][i];
            }
        }
        while (shoots_cnt > k && left <= right) {
            for (int32_t i = 0; i < m; ++i) {
                if (droids[left][i] == current_shoots[i]) {
                    current_shoots[i] = 0;
                    for (int32_t j = left + 1; j <= right; ++j) {
                        if (droids[j][i] > current_shoots[i]) {
                            current_shoots[i] = droids[j][i];
                        }
                    }
                    shoots_cnt -= droids[left][i] - current_shoots[i];
                }
            }
            ++left;
        }
        if (right - left + 1 > max_length) {
            max_length = right - left + 1;
            max_shoots = current_shoots;
        }
    }

    return max_shoots;
}

int main() {
    int32_t n, m, k;
    cin >> n >> m >> k;
    vector<vector<int32_t>> droids(n, vector<int32_t>(m));
    for (int i = 0; i < n; ++i) {
        cin >> droids[i];
    }
    cout << MaxShootCount(droids, n, m, k) << '\n';
    return 0;
}
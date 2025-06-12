#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

const int P = 1e9 + 7;
const int Q = 911382629;

vector<long long> q_pow;

void precompute_q_pow(int max_len) {
    if (max_len < 0) return;
    q_pow.resize(max_len + 1);
    q_pow[0] = 1;
    for (int i = 1; i <= max_len; ++i) {
        q_pow[i] = (q_pow[i - 1] * Q) % P;
    }
}

long long compute_hash(const string& s) {
    long long hash = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i >= q_pow.size()) {
            q_pow.resize(i + 1);
            if (i == 0) q_pow[i] = 1;
            else q_pow[i] = (q_pow[i - 1] * Q) % P;
        }
        hash = (hash + (s[i] - 'a' + 1) * q_pow[i]) % P;
    }
    return hash;
}

bool is_one_diff(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> strings(n);
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
        if (strings[i].size() > max_len) {
            max_len = strings[i].size();
        }
    }

    precompute_q_pow(max_len);

    unordered_map<int, unordered_map<long long, vector<string>>> len_to_hashes;
    for (const string& s : strings) {
        int len = s.size();
        long long hash = compute_hash(s);
        len_to_hashes[len][hash].push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int len = s.size();
        long long original_hash = compute_hash(s);
        bool found = false;

        auto it_len = len_to_hashes.find(len);
        if (it_len != len_to_hashes.end()) {
            auto& hash_map = it_len->second;
            for (int j = 0; j < s.size() && !found; ++j) {
                char original_char = s[j];
                for (char c = 'a'; c <= 'c'; ++c) {
                    if (c == original_char) continue;
                    long long new_hash = (original_hash - (original_char - 'a' + 1) * q_pow[j] % P + (c - 'a' + 1) * q_pow[j] % P + P) % P;
                    auto it_hash = hash_map.find(new_hash);
                    if (it_hash != hash_map.end()) {
                        for (const string& candidate : it_hash->second) {
                            if (is_one_diff(candidate, s)) {
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }
                }
                if (found) break;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <random>

using namespace std;

const int P = 1e9 + 7;
const int Q = 241;
const int N = 6 * 1e5 + 1;

int q[N];

random_device rd;
mt19937 gen(rd());

void PrecalculateQ()
{
    q[0] = 1;
    for (int i = 1; i < N; ++i) {
        q[i] = q[i-1] * 1LL * Q % P;
    }
}

void PrecalculateH(vector<int>& h, string& s)
{
    for (int i = 0; i < s.size(); ++i) {
        h.push_back(((i == 0 ? 0 : h[i-1]) + s[i] * 1LL * q[i]) % P);
    }
}

void PrecalcuateDiff(unordered_set<int>& s)
{
    for (int i = 0; i < N; ++i) {
        s.insert(('b' - 'a') * 1LL * q[i] % P);
        s.insert(('c' - 'a') * 1LL * q[i] % P);
        s.insert(('c' - 'b') * 1LL * q[i] % P);
        s.insert(('a' - 'b') * 1LL * q[i] % P + P);
        s.insert(('a' - 'c') * 1LL * q[i] % P + P);
        s.insert(('b' - 'c') * 1LL * q[i] % P + P);
    }
}

bool ValidateStrings(string& s1, string& s2)
{
    uniform_int_distribution<> distr(0, s1.size() - 1);
    unordered_set<int> matched;
    int i = 0;
    while (i < 5 || i < s1.size()) {
        int pos = distr(gen);
        if (s1[pos] != s2[pos]) {
            matched.insert(pos);
        }
        ++i;
    }
    if (matched.size() > 1) {
        return false;
    } else {
        return true;
    }
}


bool CompareDiffs(vector<int>& left, vector<int>& right, unordered_set<int>& diffs)
{
    int diff_str = (right.back() - left.back()) % P;
    if (diff_str < 0) diff_str += P;
    if (diffs.find(diff_str) != diffs.end()) {
        return true;
    }
    return false;
}

string CheckString(vector<vector<int>>& hashes, unordered_set<int>& diffs, vector<string>& strs, string& str)
{
    vector<int> str_hash;
    PrecalculateH(str_hash, str);

    for (int i = 0; i < hashes.size(); ++i) {
        if (hashes[i].size() != str_hash.size())
            continue;
        if (CompareDiffs(hashes[i], str_hash, diffs)) {
            if (ValidateStrings(strs[i], str)) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    PrecalculateQ();

    unordered_set<int> diffs;
    PrecalcuateDiff(diffs);

    int n, m;
    cin >> n >> m;
    vector<string> str(n);
    vector<vector<int>> hashes(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        PrecalculateH(hashes[i], str[i]);
    }

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << CheckString(hashes, diffs, str, s) << '\n';
    }

    return 0;
}


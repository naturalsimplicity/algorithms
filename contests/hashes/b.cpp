#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

// https://neerc.ifmo.ru/wiki/index.php?title=Поиск_наибольшей_общей_подстроки_двух_строк_с_использованием_хеширования
// https://ru.algorithmica.org/cs/hashing/polynomial/ - solution with complexity O(n * log(n))
// https://en.wikipedia.org/wiki/Longest_common_substring?ysclid=mbe1hry6yb905705914 - solution with complexity O(n + n)

const int P = 1e9 + 9;
const int Q = 47;
const int N = 1e5 + 1;

int q[N], h1[N], h2[N];

random_device rd;
mt19937 gen(rd());


void PrecalculateQ()
{
    q[0] = 1;
    for (int i = 1; i < N; ++i) {
        q[i] = q[i-1] * 1LL * Q % P;
    }
}

void PrecalculateH(int* h, string& s)
{
    h[0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        h[i+1] = (h[i] + s[i] * 1LL * q[i]) % P;
    }
}

int GetHashSubstring(int* h, int n, int l, int r)
{
    int h_ = (h[r] - h[l]) % P;
    if (h_ < 0) h_ += P;
    return h_ * 1LL * q[n - l] % P;
}

bool ValidateSubstrings(string& s1, string& s2, int l1, int l2, int length)
{
    uniform_int_distribution<> distr(0, length - 1);
    int i = 0;
    while (i < 3 || i < length) {
        int shift = distr(gen);
        if (s1[l1 + shift] != s2[l2 + shift]) {
            return false;
        }
        ++i;
    }
    return true;
}

int GetCommonSubstringPosition(string& s1, string& s2, int length)
{
    unordered_map<int, int> hashes;

    for (int i = 0; i < s1.size() - length + 1; ++i) {
        hashes.insert({GetHashSubstring(h1, s1.size(), i, i + length), i});
    }

    for (int i = 0; i < s2.size() - length + 1; ++i) {
        auto pos = hashes.find(GetHashSubstring(h2, s2.size(), i, i + length));
        
        if (pos != hashes.end()) {
            // Collision avoidance
            if (ValidateSubstrings(s1, s2, pos->second, i, length)) {
                return pos->second;
            }
        }
    }

    return -1;
}

string LongestCommonSubstring(string& s1, string& s2, int l, int r)
{
    if (r - l == 1) {
        return s1.substr(GetCommonSubstringPosition(s1, s2, l), l);
    } else {
        int m = (r + l) / 2;
        int pos = GetCommonSubstringPosition(s1, s2, m);
        if (pos != -1) {
            return LongestCommonSubstring(s1, s2, m, r);
        } else {
            return LongestCommonSubstring(s1, s2, l, m);
        }
    }
}


int main() 
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    PrecalculateQ();

    PrecalculateH(h1, s1);
    PrecalculateH(h2, s2);

    cout << LongestCommonSubstring(s1, s2, 1, n + 1) << '\n';

    return 0;
}

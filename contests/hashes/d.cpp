#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

// https://habr.com/ru/articles/142589/

const int P = 1e9 + 9;
const int Q = 543;
const int N = 5e3 + 1;

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

void PrecalculateH(vector<int>& h, string& s, bool reverse = false)
{
    for (int i = 0; i < s.size(); ++i) {
        int pow = (reverse ? s.size()-i-1 : i);
        h.push_back(((i == 0 ? 0 : h[i-1]) + s[i] * 1LL * q[pow]) % P);
    }
}

int Hash(vector<int>& h, int l, int r) {
	int h_ = (h[r] - (l == 0 ? 0 : h[l-1])) % P;
    if (h_ < 0) h_ += P;
    return h_;
}

bool IsPalindrome(vector<int>& forward_hash, vector<int>& reverse_hash, int l, int r)
{
    int n = forward_hash.size();
    return (Hash(forward_hash, l, r) * 1LL * q[n - l] % P) == (Hash(reverse_hash, l, r) * 1LL * q[r + 1] % P);
}

int CountPalindromes(vector<int>& forward_hash, vector<int>& reverse_hash, int l, int r, bool odd = true)
{
    int n = r - l + 1;
    vector<int> count(n);
    for (int i = 0; i < n; ++i) {
        int left = 1, right = min(i + static_cast<int>(odd), n - i);
        while (left <= right) {
            int middle = (left + right) / 2;
            if (IsPalindrome(forward_hash, reverse_hash, l + i - middle + static_cast<int>(odd), l + i + middle - 1)) {
                count[i] = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }
    int palindromes = 0;
    for (int cnt : count) {
        palindromes += cnt;
    }
    return palindromes;
}



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int q;
    cin >> q;

    PrecalculateQ();

    vector<int> forward_hash;
    vector<int> reverse_hash;

    PrecalculateH(forward_hash, s);
    PrecalculateH(reverse_hash, s, true);

    

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << CountPalindromes(forward_hash, reverse_hash, l-1, r-1) + CountPalindromes(forward_hash, reverse_hash, l-1, r-1, false) << '\n';
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

vector<int> GetPrimes(int n)
{
    vector<int> prime(n+1, 0);
    for (int i = 2; i < n+1; ++i) {
        prime[i] = i;
    }
    for (int i = 2; i < sqrt(n); ++i) {
        if (prime[i]) {
            for (int j = i*i; j < n+1; j+=i) {
                prime[j] = 0;
            }
        }
    }
    prime.erase(remove(prime.begin(), prime.end(), 0), prime.end());
    return prime;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // vector<int> prime = GetPrimes(4*n);
        // for (int i = 0; i < prime.size() && i < n; ++i) {
        //     cout << prime[i] * 2 << ' ';
        // }
        int pos = 2*n;
        for (int i = 0; i < n; ++i) {
            cout << pos << ' ';
            pos += 2;
        }
        cout << '\n';
    }
    
    return 0;
}

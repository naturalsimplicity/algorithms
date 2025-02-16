#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x;
    }
    return out;
}

void PrintBrackets(int n)
{
    int k = n;
    vector<char> brackets(2*n);
    for (int i = 0; i < n; ++i) {
        brackets[i] = '(';
    }
    for (int i = n; i < 2*n; ++i) {
        brackets[i] = ')';
    }
    int cnt = 0;
    while (cnt < n) {
        cout << brackets << '\n';
        ++cnt;
        for (int j = k-1; j > 2*(k-n); --j) { 
            // cout << "k=" << k << ",j=" << j << '\n';
            swap(brackets[j+1], brackets[j]);
            cout << brackets << '\n';
            ++cnt;
            if (cnt == n) {
                return;
            }
        }
        ++k;
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        PrintBrackets(n);
    }

    return 0;
}
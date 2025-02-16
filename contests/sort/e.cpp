#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

void LexMinVector(vector<int32_t>& a, int n)
{
    int odd = 0, even = 0;
    for (int32_t& x : a) {
        if (x % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }
    if (odd > 0 && even > 0) {
        sort(a.begin(), a.end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int32_t> a(n);
    cin >> a;
    LexMinVector(a, n);
    cout << a << '\n';
    return 0;
}
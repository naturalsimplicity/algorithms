#include <iostream>
#include <vector>
#include <numeric>
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

pair<int, int> GetFinalScore(vector<int>& a, int n)
{
    vector<int> score{0, 0};
    int left = 0, right = n-1;
    int i = 0;
    while (left <= right) {
        if (a[left] >= a[right]) {
            score[i % 2] += a[left];
            ++left;
        } else {
            score[i % 2] += a[right];
            --right;
        }
        ++i;
    }
    return {score[0], score[1]};
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    auto ans = GetFinalScore(a, n);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}

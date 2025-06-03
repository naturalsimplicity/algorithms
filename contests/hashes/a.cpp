#include <iostream>
#include <string>

using namespace std;

const int P = 1e9 + 7;
const int Q = 543;
const int N = 1e5 + 1;

int q[N], h[N];

void PrecalculateQ()
{
    q[0] = 1;
    for (int i = 1; i < N; ++i) {
        q[i] = q[i-1] * 1LL * Q % P;
    }
}

void PrecalculateH(string& s)
{
    for (int i = 0; i < s.size(); ++i) {
        h[i] = ((i == 0 ? 0 : h[i-1]) + s[i] * 1LL * q[i]) % P;
    }
}

bool IsEqual(int l1, int r1, int l2, int r2)
{
    int h1 = (h[r1] - (l1 == 0 ? 0 : h[l1-1])) % P;
    if (h1 < 0) h1 += P;
    int h2 = (h[r2] - (l2 == 0 ? 0 : h[l2-1])) % P;
    if (h2 < 0) h2 += P;
    return (q[l2] * 1LL * h1 % P) == (q[l1] * 1LL * h2 % P);
}


int main() 
{
    PrecalculateQ();

    string s;
    cin >> s;
    PrecalculateH(s);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (IsEqual(l1-1, r1-1, l2-1, r2-1) ? "Yes" : "No") << '\n';
    }


    return 0;
}

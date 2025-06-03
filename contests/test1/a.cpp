#include <iostream>
#include <vector>

using namespace std;

int GetMoreButterflies(vector<int>& v)
{
    int more_butterflies = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[0]) ++more_butterflies;
    }
    return more_butterflies;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        vector<int> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        cout << GetMoreButterflies(v) << '\n';
    }

    return 0;
}

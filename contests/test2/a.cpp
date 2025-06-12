#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> SortIndexes(vector<int>& v)
{
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    stable_sort(idx.begin(), idx.end(),
        [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});
    return idx;
}

int CountMagicEnergy(vector<int>& v, vector<int>& idx)
{
    int energy = 0;
    for (int i = 0; i < v.size(); ++i) {
        energy += v[idx[i]] * i + 1;
    }
    return energy;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<int> sorted_indexes = SortIndexes(v);
    cout << CountMagicEnergy(v, sorted_indexes) << '\n';
    for (int i : sorted_indexes) {
        cout << i + 1 << ' ';
    }
    cout << '\n';

    return 0;
}

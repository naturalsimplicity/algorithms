#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

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

int MaxSkillsNaive(vector<int>& s, vector<int>& r, int n, int m)
{
    vector<int64_t> idx(r.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
        [&r](size_t i1, size_t i2) {return r[i1] >= r[i2];});

    map<int, vector<int>> sr;
    for (int i : idx) {
        if (sr[s[i]].size() > 0 && sr[s[i]].back() + r[i] > 0) {
            sr[s[i]].push_back(sr[s[i]].back() + r[i]);
        } else if (r[i] > 0) {
            sr[s[i]].push_back(r[i]);
        }
    }
    int max_s = 0;
    for (auto x : sr) {
        // cout << x.first << ": [ " << x.second << "]" << '\n';
        if (x.second.size() > max_s) {
            max_s = x.second.size();
        }
    }
    vector<int> prefixes(max_s);
    for (int i = 0; i < max_s; ++i) {
        for (int j = 1; j < m+1; ++j) {
            if (i < sr[j].size()) {
                prefixes[i] += sr[j][i];
            }
        }
    }
    // cout << prefixes << '\n';
    int max_sum = 0;
    for (int x : prefixes) {
        if (x > max_sum) {
            max_sum = x;
        }
    }
    return max_sum;
}

int32_t MaxSkillsFast(vector<int32_t>& s, vector<int32_t>& r, int n, int m)
{
    vector<int32_t> idx(n);
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
        [&r](size_t i1, size_t i2) {return r[i1] >= r[i2];});

    vector<int32_t> part_sum(m), cnt(m), prefixes(n);
    for (int32_t i : idx) {
        // cout << "i=" << i << ",s[i]=" << s[i] << ",r[i]=" << r[i] << ",cnt[s[i]-1]=" << cnt[s[i]-1] << '\n';
        if (part_sum[s[i]-1] + r[i] > 0) {
            part_sum[s[i]-1] += r[i];
            prefixes[cnt[s[i]-1]] += part_sum[s[i]-1];
            ++cnt[s[i]-1];
        }
    }
    // cout << part_sum << '\n';
    // cout << cnt << '\n';
    // cout << prefixes << '\n';

    int32_t max_sum = 0;
    for (int32_t x : prefixes) {
        if (x > max_sum) {
            max_sum = x;
        }
    }
    return max_sum;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int32_t> s(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> r[i];
    }
    cout << MaxSkillsFast(s, r, n, m) << '\n';
    return 0;
}


/*
6 3
1 -5
1 -10
2 -7
2 -14
3 5
3 5
ANS: 10

6 2 
1 100
1 2
1 -1
2 5
2 4
2 3
ANS: 113
*/
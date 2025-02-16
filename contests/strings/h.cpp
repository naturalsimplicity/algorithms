#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    int n;
    string str;
    cin >> n;
    cin >> str;

    for (int i = 1; i < n; ++i) {
        ++m[str.substr(i-1, 2)];
    }

    int max_cnt = 0;
    string most_freq_str;
    for (auto const& x : m) {
        if (x.second > max_cnt) {
            max_cnt = x.second;
            most_freq_str = x.first;
        }
    }

    cout << most_freq_str << '\n';


    return 0;
}
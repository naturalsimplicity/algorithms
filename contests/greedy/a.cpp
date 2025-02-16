#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        int switches = 0, result = 0, zero_ranges = (s[0] == '0' ? 1 : 0);
        if (s.size() > 1) {    
            for (size_t j = 1; j < s.size(); ++j) {
                if (s[j] != s[j-1]) {
                    ++switches;
                    if (s[j] == '0') {
                        ++zero_ranges;
                    }
                }
            }
        }
        // 0101
        if (switches > 2) {
            result = 2;
        } else if (switches == 2) {
            if (zero_ranges < 2) {
                result = 1;
            } else {
                result = 2;
            }
        } else if (switches == 1) {
            result = 1;
        } else {
            if (s[0] == '1') {
                result = 0;
            } else {
                result = 1;
            }
        }
        cout << result << '\n';
    }
    return 0;
}
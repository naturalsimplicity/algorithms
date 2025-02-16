#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string str;
    for (int i = 0; i < t; ++i)
    {
        cin >> str;
        bool palindrome = true;
        if (str.size() == 1) {
            cout << -1 << '\n';
            continue;
        }
        for (int j = 0; j < str.size() / 2; ++j) {
            if (str[j] != str[str.size() - j - 1]) {
                palindrome = false;
                break;
            }
        }
        if (palindrome) {
            bool fixed = false;
            for (int k = 1; k < str.size(); ++k) {
                if (str[k] != str[k-1]) {
                    swap(str[k], str[k-1]);
                    fixed = true;
                    break;
                }
            }
            if (!fixed) {
                str = "-1";
            }

        } 
        cout << str << '\n';
    }
    return 0;
}
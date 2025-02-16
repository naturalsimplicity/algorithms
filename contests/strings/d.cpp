#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str, str2 = "";
        cin >> str;
        if (str.size() > 2) {
            for (int j = 0; j < str.size(); ++j) {
                if (j % 2 == 0 || j == 0 || j == str.size()-1) {
                    str2 += str[j];
                }
            }
        } else {
            str2 = str;
        }
        cout << str2 << '\n';
    }

    return 0;
}
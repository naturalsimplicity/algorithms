#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q;
    cin >> q;
    string str;
    for (int i = 0; i < q; ++i)
    {
        cin >> str;

        if (str.size() == 1) {
            cout << str << '\n';
            continue;
        }
        int cnt = 0;
        for (int j = 1; j < str.size(); ++j)
        {
            if (str[j] > str[j-1]) {
                ++cnt;
            } else if (str[j] < str[j-1]) {
                --cnt;
            }
        }
        if (cnt > 0) {
            str[str.size() - 1] = 'a';
        } else if (cnt < 0) {
            str[str.size() - 1] = 'b';
        }
        cout << str << '\n';
    }
    return 0;
}
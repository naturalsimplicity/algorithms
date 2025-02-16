#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    set<char> chars {};

    for (int i = 0; i < n; ++i) {
        chars.insert(tolower(str[i]));
    }

    cout << (chars.size() == 26 ? "YES" : "NO") << '\n';

    return 0;
}
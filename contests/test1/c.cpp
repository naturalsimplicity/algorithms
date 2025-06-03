#include <iostream>
#include <vector>
#include <string>

using namespace std;


int GetMinKeyboardLength(string& s)
{
    char max_char = 'a';
    for (char c : s) {
        if (c > max_char) {
            max_char = c;
        }
    }
    return (int)(max_char - 'a') + 1;
}


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << GetMinKeyboardLength(s) << '\n';
    }
    return 0;
}

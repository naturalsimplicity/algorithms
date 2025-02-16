#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int upper = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) {
            upper += 1;
        }
    }

    if (upper > s.size() - upper) {
        for (auto& c : s) c = toupper(c);
    } else {
        for (auto& c : s) c = tolower(c);
    }
    cout << s << '\n';

    return 0;
}
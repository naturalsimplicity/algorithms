#include <iostream>
#include <vector>
#include <string>

using namespace std;

string CompressNickname(string& s)
{
    if (s.size() <= 10) {
        return s;
    } else {
        string compressed;
        compressed.push_back(s.front());
        compressed += to_string(s.size() - 2);
        compressed.push_back(s.back());
        return compressed;
    }
}



int main()
{
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << CompressNickname(s) << '\n';
    }
    return 0;
}

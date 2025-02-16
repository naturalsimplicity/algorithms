#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string password;
    cin >> password;
    int n;
    cin >> n;
    bool full = false, ends_first = false, starts_second = false;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        if (word == password) {
            full = true;
        }
        if (word.back() == password.front()) {
            ends_first = true;
        }
        if (word.front() == password.back()) {
            starts_second = true;
        }
    }
    if (full || starts_second && ends_first) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';

    return 0;
}
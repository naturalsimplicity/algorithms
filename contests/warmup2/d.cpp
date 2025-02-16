#include <string>
#include <iostream>
#include <set>

using namespace std;

int main() {
    string nick;
    cin >> nick;

    set<char> chars{};

    for (int i = 0; i < nick.size(); ++i) {
        chars.insert(nick[i]);
    }
    if (chars.size() % 2 == 1) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }
    cout << '\n';

    return 0;
}
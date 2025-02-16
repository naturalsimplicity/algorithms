#include <string>
#include <iostream>
using namespace std;

int main()
{
    string players;
    cin >> players;

    bool dangerous = false;
    int series = 1;
    for (int i = 1; i < players.size(); ++i) {
        if (players[i] == players[i-1]) {
            series += 1;
        } else {
            series = 1;
        }
        if (series >= 7) {
            dangerous = true;
            break;
        }
    }

    cout << (dangerous ? "YES" : "NO") << '\n';

    return 0;
}
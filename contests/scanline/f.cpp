#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

struct event {
    int player, x, type;

    event (int player, int x, int type):
        player(player), x(x), type(type) {}
};


void Solve()
{
    int n;
    cin >> n;
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back(event(i, l, 0));
        events.push_back(event(i, r, 1));
    }
    sort(events.begin(), events.end(),
        [](event a, event b) {return (a.x < b.x || (a.x == b.x && a.type < b.type));});

    vector<int> player_contacts(n);
    set<int> current_players;
    int current_contacts = 0;
    for (auto it = events.begin(); it != events.end(); ++it) {
        if (it->type == 0) {
            for (auto p : current_players) {
                ++player_contacts[p];
            }
            player_contacts[it->player] = current_contacts;
            current_players.insert(it->player);
            ++current_contacts;
        }
        
        if (it->type == 1) {
            current_players.erase(it->player);
            --current_contacts;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << player_contacts[i] << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Solve();
    return 0;
}
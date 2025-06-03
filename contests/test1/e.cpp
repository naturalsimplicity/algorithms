#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int GetMinTowersCount(vector<long long>& bricks)
{
    sort(bricks.begin(), bricks.end(), greater<>());
    vector<long long> towers;
    towers.push_back(bricks[0]);
    for (int i = 1; i < bricks.size(); ++i) {
        bool found = false;
        for (int j = 0; j < towers.size(); ++j) {
            if (bricks[i] < towers[j]) {
                towers[j] = bricks[i];
                found = true;
                break;
            }
        }
        if (!found) {
            towers.push_back(bricks[i]);
        }
    }
    return towers.size();
}


int main()
{
    int n;
    cin >> n;
    vector<long long> bricks(n);
    for (int i = 0; i < n; ++i) {
        cin >> bricks[i];
    }
    cout << GetMinTowersCount(bricks) << '\n';

    return 0;
}

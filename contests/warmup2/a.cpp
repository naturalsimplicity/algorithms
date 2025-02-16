#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string expr;
    cin >> expr;

    map<int, int> nums{};

    for (int i = 0; i < expr.size(); ++i) {
        if (expr[i] == '+') {
            continue;
        }
        nums[expr[i] - '0'] += 1;
    }
    bool is_first = true;
    for (const auto& n : nums) {
        for (int j = 0; j < n.second; ++j) {
            if (is_first) {
                is_first = false;
            } else {
                cout << "+"s;
            }
            cout << n.first;
        }
    }
    cout << '\n';

    return 0;
}
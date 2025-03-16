#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int Solve(string& commands, int n, int x, int y)
{
    int reserve = n - abs(x) - abs(y);
    if (reserve < 0 || reserve % 2 == 1) {
        return -1;
    }
    int target_x = 0, target_y = 0;
    for (char& c : commands) {
        switch (c) {
            case 'U':
                ++target_y;
                break;
            case 'D':
                --target_y;
                break;
            case 'R':
                ++target_x;
                break;
            case 'L':
                --target_x;
                break;
        }
    }
    if (target_x == x && target_y == y) {
        return 0;
    }

    int min_subsection = -1;
    int pos_x = target_x, pos_y = target_y;
    int ptr1 = 0, ptr2 = 0;
    cout << "ptr1=" << ptr1 << ",ptr2=" << ptr2 << ",pos_x=" << pos_x << ",pos_y=" << pos_y << '\n'; 
    while (ptr1 < n) {
        if (commands[ptr2] == 'R' || commands[ptr2] == 'L') {
            if (abs(x - pos_x) == 1) {
                if (y - pos_y > 0) { // replace to U
                    pos_y += 1; // cout << ptr2 << ": replace to U" << '\n';
                } else {
                    pos_y -= 1; // cout << ptr2 << ": replace to D" << '\n'; // replace to D
                }
                if (commands[ptr2] == 'L') {
                    pos_x += 1;
                } else {
                    pos_x -= 1;
                }
            } else {
                if (commands[ptr2] == 'R' && x - pos_x < 0) {
                    pos_x -= 2; // cout << ptr2 << ": replace to L" << '\n'; // replace to L
                } else if (commands[ptr2] == 'L' && x - pos_x > 0) {
                    pos_x += 2; // cout << ptr2 << ": replace to R" << '\n'; // replace to R
                } else if (x - pos_x == 0 && y - pos_y != 0) {
                    if (y - pos_y > 0) {
                        pos_y += 1;
                    } else {
                        pos_y -= 1;
                    }
                    if (commands[ptr2] == 'L') {
                        pos_x += 1;
                    } else {
                        pos_x -= 1;
                    }
                }
            }
            // else do nothing
        } else { // U and D
            if (abs(y - pos_y) == 1) {
                if (x - pos_x > 0) { // replace to R
                    pos_x += 1; // cout << ptr2 << ": replace to R" << '\n';
                } else {
                    pos_x -= 1; // cout << ptr2 << ": replace to L" << '\n'; // replace to L
                }
                if (commands[ptr2] == 'D') {
                    pos_y += 1;
                } else {
                    pos_y -= 1;
                }
            } else {
                if (commands[ptr2] == 'U' && y - pos_y < 0) {
                    pos_y -= 2; // cout << ptr2 << ": replace to D" << '\n'; // replace to D
                } else if (commands[ptr2] == 'D' && y - pos_y > 0) {
                    pos_y += 2; // cout << ptr2 << ": replace to U" << '\n'; // replace to U
                } else if (y - pos_y == 0 && x - pos_x != 0) {
                    if (x - pos_x > 0) {
                        pos_x += 1;
                    } else {
                        pos_x -= 1;
                    }
                    if (commands[ptr2] == 'D') {
                        pos_y += 1;
                    } else {
                        pos_y -= 1;
                    }
                }
            } 
        }

        // cout << "ptr1=" << ptr1 << ",ptr2=" << ptr2 << ",pos_x=" << pos_x << ",pos_y=" << pos_y << '\n'; 
        if (ptr2 == n - 1 || x == pos_x && y == pos_y) {
            if (x == pos_x && y == pos_y && (ptr2 - ptr1 + 1 < min_subsection || min_subsection == -1)) {
                min_subsection = ptr2 - ptr1 + 1;
                // cout << "new min_subsection=" << min_subsection << '\n';
            }
            ++ptr1;
            ptr2 = ptr1;
            pos_x = target_x, pos_y = target_y;
            // cout << "ptr1=" << ptr1 << '\n';
            continue;
        }
        ++ptr2;
    }


    return min_subsection;
}

// 7
// RUUURUR
// -2 3
// ans = 3

// 6
// ULRDRL
// 1 1
// ans = 1

// 6
// RRLLRR
// 0 4
// ans = 5

int main() {
    int n, x, y;
    cin >> n;
    string commands;
    cin >> commands;
    cin >> x >> y;
    cout << Solve(commands, n, x, y) << '\n';

    return 0;
}

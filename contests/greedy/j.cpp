#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (T& x : a) {
        in >> x;
    }
    return in;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> users(n);
        cin >> users;

        int likes = 0;
        for (auto& x : users) {
            if (x != 2) {
                ++likes;
            }
        }
        cout << likes << '\n';
    }

    return 0;
}
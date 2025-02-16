#include <iostream>
#include <vector>

using namespace std;

int IntPow(int base, int power)
{
    int res = 1;
    for (int i = 0; i < power; ++i) {
        res *= base;
    }
    return res;
}

int GetPressedButtons(int x)
{
    int count = 0;
    for (int i = 1; i < 10; ++i) {
        int num = 0;
        for (int j = 0; j < 4; ++j) {
            num += i * IntPow(10, j);
            count += j + 1;
            // cout << num << ' ';
            if (num == x) {
                // cout << '\n';
                return count;
            }
        }
    }
    return count;
}


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << GetPressedButtons(x) << '\n';
        
    }
    
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

uint32_t IntPow(uint32_t base, uint32_t power)
{
    uint32_t res = 1;
    for (int i = 0; i < power; ++i) {
        res *= base;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        uint64_t x, y;
        cin >> x >> y;
        int count = 0;
        for (int i = 9; i >= 0; --i) {
            uint64_t num = x * IntPow(10, i);
            count += y / num;
            y = y % num;
            // cout << "i=" << i << ",count=" << count << ", n=" << y << '\n';
        }
        if (y > 0) {
            count += y;
        }
        cout << count << '\n';
        
    }

    return 0;
}
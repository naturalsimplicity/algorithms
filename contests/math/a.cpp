#include <iostream>
#include <string>

using namespace std;

uint64_t IntPow(unsigned int base, unsigned int power)
{
    uint64_t res = 1;
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
        uint64_t n;
        cin >> n;
        int count = 0;
        for (int i = 15; i >= 0; --i) {
            uint64_t num = 2050 * IntPow(10, i);
            count += n / num;
            n = n % num;
            // cout << "i=" << i << ",count=" << count  << ", n=" << n << '\n';
        }
        if (n > 0) {
            count = -1;
        }
        cout << count << '\n';
    }
    
    return 0;
}

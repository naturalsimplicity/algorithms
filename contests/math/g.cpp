#include <iostream>

using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--) {
        uint32_t a, b;
        cin >> a >> b;
        // 6  = 0110
        // 12 = 1100      
        // 4  = 0100
        uint32_t x = a & b;
        cout << (a ^ x) + (b ^ x) << '\n';
    }
    
    return 0;
}

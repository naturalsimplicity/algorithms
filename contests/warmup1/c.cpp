#include <iostream>
using namespace std;

unsigned long long ceil(unsigned long long a1, unsigned long long a2)
{
    unsigned long long p = a1 / a2;
    if (p * a2 < a1) {
        p += 1;
    }
    return p;
}

int main() 
{
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    
    cout << ceil(n, a) * ceil(m, a) << endl;
    return 0;
}
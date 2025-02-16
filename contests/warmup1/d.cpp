#include <iostream>
using namespace std;

int main() 
{
    int n, m1, m2, m3;
    cin >> n;
    int cities_with_tax = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m1 >> m2 >> m3;
        if (m1 + m2 + m3 > 1) {
            cities_with_tax += 1;
        }
    }
    cout << cities_with_tax << endl;
    return 0;
}
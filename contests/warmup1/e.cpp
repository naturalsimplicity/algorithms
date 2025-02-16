#include <iostream>
#include <array>
using namespace std;

enum {
    max_participants=50
};

int main() 
{
    int n, k, num_proceed = 0;
    cin >> n >> k;
    array<int, max_participants> a;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int i = 0;
    while (a[i] >= a[k-1] && a[i] > 0 && i < n) {
        ++num_proceed;
        ++i;
    }
    cout << num_proceed << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n, val = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str[1] == '+') {
            ++val;
        } else {
            --val;
        }
    }
    cout << val << endl;
    return 0;
}
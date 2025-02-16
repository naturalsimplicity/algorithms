#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); ++i) {
        if (tolower(str1[i]) < tolower(str2[i]))
        {
            cout << -1;
            break;
        } else if (tolower(str1[i]) > tolower(str2[i]))
        {
            cout << 1;
            break;
        } else if (i == str1.size() - 1)
        {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
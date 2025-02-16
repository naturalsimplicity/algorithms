#include <string>
#include <iostream>

using namespace std;

int main() {
    string cap;
    cin >> cap;
    
    if (!isupper(cap[0])) {
        cap[0] = toupper(cap[0]);
    }
    cout << cap << '\n';
 
    return 0;
}
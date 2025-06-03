#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> links;
    while (n--) {
        string s;
        cin >> s;
        
        if (links.find(s) == links.end()) {
            links.insert({s, 0});
            cout << "OK" << '\n';
        } else {
            ++links[s];
            cout << s + to_string(links[s]) << '\n';
        }

    }    

    return 0;
}

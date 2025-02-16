#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string vowels = "aoyeui";
    string in, out = ""s;
    cin >> in;
    for (int i = 0; i < in.size(); ++i) {
        char chr_lower = tolower(in[i]);
        if (vowels.find(chr_lower) == string::npos) {
            out.push_back('.');
            out.push_back(tolower(in[i]));
        }
    }
    cout << out << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string soundex(string& str)
{
    string code;
    code += str[0];

    for (size_t i = 1; i != str.size(); ++i) {
        char n;

        switch (str[i]) {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                n = '1';
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                n = '2';
                break;
            case 'd':
            case 't':
                n = '3';
                break;
            case 'l':
                n = '4';
                break;
            case 'm':
            case 'n':
                n = '5';
                break;
            case 'r':
                n = '6';
                break;
            default:
                n = '-';
        }

        if (code.back() != n && n != '-') {
            code += n;
        }
    }

    if (code.size() > 4) {
        code = code.substr(0, 4);
    } else if (code.size() < 4) {
        code.insert(code.size(), 4 - code.size(), '0');
    }
    return code;
}

int main() 
{
    string str;
    cin >> str;
    cout << soundex(str) << '\n';

    return 0;
}
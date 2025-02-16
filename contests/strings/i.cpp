#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
Двоичная строка — это такая строка, каждый символ которой — либо 0, либо 1.
Назовем две двоичные строки 𝑎 и 𝑏 одинаковой длины похожими,
если хотя бы в одной позиции их символы совпадают (существует такое число 𝑖, что 𝑎𝑖=𝑏𝑖).
Например:
- 10010 и 01111 похожи (у них один и тот же символ в позиции 4);
- 10010 и 11111 похожи;
- 111 и 111 похожи;
- 0110 и 1001 не являются похожими.
Вам дано целое число 𝑛 и двоичная строка 𝑠, состоящая из 2𝑛−1 символов.
Обозначим за 𝑠[𝑙..𝑟] непрерывную подстроку 𝑠, начиная с 𝑙-го символа 
и заканчивая 𝑟-м символом (иными словами, 𝑠[𝑙..𝑟]=𝑠𝑙𝑠𝑙+1𝑠𝑙+2…𝑠𝑟).

Постройте двоичную строку 𝑤 длины 𝑛, похожую на все строки из этого списка:
𝑠[1..𝑛], 𝑠[2..𝑛+1], 𝑠[3..𝑛+2], ..., 𝑠[𝑛..2𝑛−1].
*/

int binaryToDecimal(const string& binary)
{
    int power = 0;
    int decimal = 0;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        ++power;
    }
    return decimal;
}

string decimalToBinary(int decimal, int scale)
{
    string binary;
    for (int i = scale - 1; i >= 0; --i) {
        if (decimal >= pow(2, i)) {
            binary += '1';
            decimal -= pow(2, i);
        } else {
            binary += '0';
        }
    }
    return binary;
}

int findSimilarInt(int n, const string& str)
{
    vector<int> exceptions;
    int max_value = pow(2, n) - 1;
    for (int j = 0; j < n; ++j) {
        int exc = max_value - binaryToDecimal(str.substr(j, n));
        exceptions.push_back(exc);
    }
    for (int j = 0; j <= max_value; ++j) {
        if (find(exceptions.begin(), exceptions.end(), j) == exceptions.end()) {
            return j;
        }
    }
    return -1; // if no similar number found
}

string invert(const string& binary)
{
    string inverted;
    for (int i = 0; i < binary.size(); ++i) {
        inverted += (binary[i] == '1' ? '0' : '1');
    }
    return inverted;
}

void increment(string& binary)
{
    string incremented;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '0') {
            binary[i] = '1';
            break;
        } else {
            binary[i] = '0';
        }
    }
}

string findSimilar(int n, const string& str)
{
    vector<string> exceptions;
    for (int j = 0; j < n; ++j) {
        exceptions.push_back(invert(str.substr(j, n)));
    }
    // init zero binary string
    string similar;
    for (int k = 0; k < n; ++k) {
        similar += '0';
    }
    // there can be no more than n + 1 exceptions
    for (int j = 0; j < n + 1; ++j) {
        if (find(exceptions.begin(), exceptions.end(), similar) != exceptions.end()) {
            increment(similar);
        } else {
            break;
        }
    }
    return similar;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        string str;
        cin >> n;
        cin >> str;
        cout << findSimilar(n, str) << '\n';
        // works only for n <= 31 (due to int overflow)
        // cout << decimalToBinary(findSimilarInt(n, str), n) << '\n'; 
    }
    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void Solve()
{
    stack<int> operands;
    string str;
    getline(cin, str);
    istringstream iss(str);
    string operand;
    while (iss >> operand) {
        if (operand == "+" || operand == "-" || operand == "*") {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            int result;
            if (operand == "+") {
                result = left + right;
            } else if (operand == "-") {
                result = left - right;
            } else {
                result = left * right;
            }
            operands.push(result);
        } else {
            operands.push(stoi(operand));
        }
    }
    cout << operands.top() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}
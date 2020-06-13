/*open with vscode
geeksforgeeks.org/expression-evaluation
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int64 applyOp(int64 a, int64 b, char op) {
    if (op == '+') return a + b;
    if (op == '*') return a * b;
    if (op == '-') return a - b;
    return a / b;
}
int64 compute(string s) {
    int i;
    stack <int64> values;
    stack <char> ops; //toan tu
    for (i=0; i<s.length(); i++) {
        if (s[i] == '(') ops.push(s[i]);
        else if (isdigit(s[i])) {
            int64 val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int64 val2 = values.top(); values.pop();
                int64 val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op)); 
            }
            if (!ops.empty()) ops.pop();
        }
        else { //s[i] = toan tu
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int64 val2 = values.top(); values.pop();
                int64 val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty()) {
        int64 val2 = values.top(); values.pop();
        int64 val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        cout << compute(s) << endl;
    }
}
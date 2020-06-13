/*open with vscode
stack<char> stk
string ans = "";
for x in xâu s: 
    nếu gặp '(' =>> push '(' vào stk
    nếu gặp toán hạng =>> ans += toán hạng
    nếu gặp dấu toán tử:
        y = top stack
        nếu priority(X) >= priority(y) push x
        nếu p(x)<p(y): 
            ans+=y
            pop
            push x
        *note: hàm priority lưu ý TH stack empty và y='('
    nếu gặp ')'
        in stack ra cho đến khi gặp '('
        pop dấu '(' đáy luôn
hết for trong stack sẽ có thể còn
in ra hết
*/
#include <bits/stdc++.h>
using namespace std;
int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '^') return 3;
    return 0;
}
string solve(string exp) {
    stack <char> stk;
    string ans = "";
    for (int i=0; i<exp.size(); i++) {
        if (exp[i] == '(') stk.push(exp[i]);
        else if (isalpha(exp[i])) ans = ans + exp[i];
        else if (exp[i] == ')') {
            while (!stk.empty() && stk.top() != '(') {
                ans = ans + stk.top();
                stk.pop();
            }
            if (!stk.empty() && stk.top() == '(') stk.pop();
        }
        else {
            while (!stk.empty() && priority(exp[i]) <= priority(stk.top())) {
                ans = ans + stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
    }
    while (!stk.empty() && stk.top() != '(') {
        ans = ans + stk.top();
        stk.pop();
    }
    return ans;
}
int main() {
    int t; cin >> t;
    string exp;
    while (t--) {
        cin >> exp;
        cout << solve(exp) << endl;
    }
}
/*open with vscode
stack stk 
stk.push(0) // 1 là đảo 0 là k đảo
nếu là dấu + hoặc -
    nếu stk.top() là 1 ans[index++] = daoDau()
    else ans[index++] = dấu (không đổi)
nếu là '('
    nếu empty: k lam gi ca
    nếu trước là +; push(stk.top) 
    nếu trước là -:
        nếu top là 0 push vào 1
        nếu top là 1 push vào 0
    *note: có case trước '(' không phải dấu. => k dùng else
nếu là ')'
    pop
còn lại là toán hạng: đẩy vào ans;
*/
#include <bits/stdc++.h>
using namespace std;
char daoDau(char c) {
    if (c == '+') return '-';
    else return '+';
}
string solve (string s) {
    string ans; ans.resize(s.size());
    stack<int> stk;
    int index = 0;
    stk.push(0);
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (stk.top() == 1) 
                ans[index++] = daoDau(s[i]);
            else ans[index++] = s[i];
        }
        else if (s[i] == '(') {
            if (i == 0) stk.push(0);
            else if (s[i-1] == '+') stk.push(stk.top());
            else if (s[i-1] == '-') {
                int x;
                if (stk.top() == 0) x = 1;
                else x = 0;
                stk.push(x);
            }
        }
        else if (s[i] == ')')
            stk.pop();
        else 
            ans[index++] = s[i];
    }
    ans.resize(index);
    return ans;
}
int main() {
    int t; cin >> t;
    string P;
    while (t--) {
        cin >> P;
        cout << solve(P) << endl;
    }
}
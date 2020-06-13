/*open with vscode
(a + b*(c-d))
duyệt từ trái sang phải
    nếu gặp ')' 
        tìm stack ngược về cho khi nào thấy '('
            nếu trong quá trình lùi dần mà gặp toán tử 
            thì tức là biểu thức k thừa dấu ngoặc 
            (mean giữa 2 dấu ngoặc đã có toán tử)
    k phải ')' : push vào stack
*/
#include <bits/stdc++.h>
using namespace std;
string solve(string s) {
    stack <char> stk;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ')') {
            char top = stk.top();
            stk.pop();
            bool flag = true; //true = thừa
            while (top != '(') {
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                        flag = false;
                top = stk.top();
                stk.pop();
            }
            if (flag == true) 
                return "Yes";
        }
        else stk.push(s[i]);
    }
    return "No";
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        getline(cin >> ws, s);
        cout << solve(s) << endl;
    }
}
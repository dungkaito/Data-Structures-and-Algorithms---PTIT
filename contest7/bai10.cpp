/*open with vscode
giống bài 8
*/
#include <bits/stdc++.h>
using namespace std;
char daoDau(char c) {
    if (c == '+') return '-';
    else return '+';
}
string simplified(string s) {
    string res;
    stack<int> st;
    st.push(0);
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (!st.empty() && st.top() == 1) 
                res += daoDau(s[i]);
            else res += s[i];
        }
        else if (s[i] == '(') {
            if (i==0) st.push(0);
            if (st.empty()) continue;
            if (s[i-1] == '+') st.push(st.top());
            else if (s[i-1] == '-') {
                int x;
                if (st.top() == 0) x = 1;
                else x = 0;
                st.push(x);
            }
        }
        else if (!st.empty() && s[i] == ')')
            st.pop();
        else if (isalpha(s[i]))
            res += s[i];
    }
    return res;
}
int main() {
    int t; cin >> t;
    string P1, P2;
    while (t--) {
        cin >> P1 >> P2;
        // cout << simplified(P1) << endl;
        if (simplified(P1) == simplified(P2)) cout << "YES\n";
        else cout << "NO\n";
    }
}
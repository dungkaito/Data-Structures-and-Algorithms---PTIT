#include <bits/stdc++.h>
using namespace std;
bool checkToanTu(char c) {
    if (c == '+' || c== '-' || c == '*' || c== '/'
        || c == '%' || c == '^')
        return true;
    return false;
}
string solve(string exp) {
    stack<string> st;
    int n = exp.length();
    for (int i=n-1; i>=0; --i) {
        if (checkToanTu(exp[i])){
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string tmp = '(' + a + exp[i] + b + ')';
            st.push(tmp);
        }
        else st.push(string(1, exp[i]));
    }
    return st.top();
}
int main() {
    int t; cin >> t;
    string exp;
    while (t--) {
        cin >> exp;
        cout << solve(exp) << endl;
    }
}
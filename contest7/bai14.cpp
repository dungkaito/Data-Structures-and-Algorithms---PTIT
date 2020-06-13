#include <bits/stdc++.h>
using namespace std;
bool checkToanTu(char c) {
    if (c == '+' || c== '-' || c == '*' || c== '/'
        || c == '%' || c == '^')
        return true;
    return false;
}
string solve(string s) {
    stack<string> st;
    int n = s.length();
    for (int i=0; i<n; i++) {
        if (checkToanTu(s[i])) {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string tmp = s[i] + b + a;
            st.push(tmp);
        }
        else st.push(string(1, s[i]));
    }
    return st.top();
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        cout << solve(s) << endl;
    }
}
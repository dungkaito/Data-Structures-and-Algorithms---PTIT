#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int64 cal(int64 a, int64 b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return a / b;
}
int64 solve(string s) {
    stack <int64> st;
    int n = s.length();
    for (int i=0; i<n; ++i) {
        if (isdigit(s[i])) 
            st.push(s[i] - '0');
        else {
            int64 a = st.top(); st.pop();
            int64 b = st.top(); st.pop();
            int64 tmp = cal(b, a, s[i]);
            st.push(tmp);
        }
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
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int64 cal(int64 x, int64 y, char c) {
    if (c == '+') return x + y;
    if (c == '-') return x - y;
    if (c == '*') return x * y;
    return x / y;
}
int64 solve(string s) {
    stack <int64> st;
    int n = s.length();
    for (int i=n-1; i>=0; --i) {
        if (isdigit(s[i])) 
            st.push(s[i] - '0');
        else {
            int64 x = st.top(); st.pop();
            int64 y = st.top(); st.pop();
            int64 tmp = cal(x, y, s[i]);
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
#include <bits/stdc++.h> 
using namespace std;
typedef long long int64;
int64 calc(string s) {
    int64 res = 0;
    for (int64 i=0; i<s.length(); i++)
        res = res * 10 + s[i] - '0';
    return res;
}
string solve(int n) {
    queue <string> q; q.push("1");
    while (1) {
        string top = q.front(); q.pop();
        if (calc(top) % (int64)n == 0) return top;
        q.push(top + "0");
        q.push(top + "1");
    }
}
int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
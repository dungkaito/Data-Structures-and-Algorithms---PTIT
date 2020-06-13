#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    queue <string> q;
    q.push("1");
    while (n--) {
        string top = q.front(); q.pop();
        cout << top << " ";
        q.push(top + "0");
        q.push(top + "1");
    }
}
int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
    queue <int> q;
    q.push(9);
    while (1) {
        int top = q.front(); q.pop();
        if (top % n == 0) return top;
        q.push(top * 10);
        q.push(top * 10 + 9);
    }
}
int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
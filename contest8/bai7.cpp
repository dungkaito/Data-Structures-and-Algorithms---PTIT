#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int64 solve(int64 n) {
    int64 ans = 0;
    queue <int64> q; q.push(1);
    while (1) {
        int64 top = q.front(); q.pop();
        if (top > n) break;
        ans++;
        q.push(top * 10);
        q.push(top * 10 + 1);
    }
    return ans;
}
int main() {
    int t; cin >> t;
    int64 n;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
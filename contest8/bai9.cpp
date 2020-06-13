#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

int solve(int n, int t) {
    // chuyen s thanh t
    queue < pii > q; 
    q.push(mp(n, 0)); // se la so buoc

    set <int> visit;
    visit.insert(n);

    while (1) {
        pii top = q.front(); q.pop();

        if (top.fi == t) return top.se;

        if (top.fi - 1 > 0 && visit.find(top.fi - 1) == visit.end()) {
            q.push(mp(top.fi - 1, top.se + 1));
            visit.insert(top.fi - 1);
        }

        if (top.fi * 2 < 20000 && visit.find(top.fi * 2) == visit.end()) {
            q.push(mp(top.fi * 2, top.se + 1));
            visit.insert(top.fi * 2);
        }
    }
}

int main() {
    int test, s, t; cin >> test;
    while (test--) {
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}
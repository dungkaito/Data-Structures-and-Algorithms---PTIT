#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

int solve(int n) {
    queue < pii > q;
    q.push(mp(n, 0));
    set <int> visit;
    visit.insert(n);
    while (1) {
        pii top = q.front(); q.pop();
        
        if (top.fi == 1) return top.se;
        if (top.fi - 1 == 1) return top.se + 1;// phai them dong nay moi xanh?

        //thao tac a
        if (visit.find(top.fi - 1) == visit.end()) {
            q.push(mp(top.fi - 1, top.se + 1));
            visit.insert(top.fi - 1);
        }

        //thao tac b
        for (int i=2; i*i<=(top.fi); i++) {
            if (top.fi % i == 0) {
                if (visit.find(top.fi / i) == visit.end()) {
                    q.push(mp(top.fi / i, top.se + 1));
                    visit.insert(top.fi / i);
                }
            }
        }
    }
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
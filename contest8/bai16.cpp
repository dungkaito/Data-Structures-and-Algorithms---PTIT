#include <bits/stdc++.h>
using namespace std;

#define vii pair<vector<int>, int>
#define mp make_pair
#define fi first
#define se second

vector <int> a(6), b(6), L(6), R(6);

int solve() {
    queue <vii> q;
    q.push(mp(a, 0));

    set < vector<int> > visit;
    visit.insert(a);

    while (!q.empty()) {
        vii t = q.front(); q.pop();
        
        if (t.fi == b) return t.se;

        L[0] = t.fi[3]; L[1] = t.fi[0]; L[2] = t.fi[2];
        L[3] = t.fi[4]; L[4] = t.fi[1]; L[5] = t.fi[5];

        R[0] = t.fi[0]; R[1] = t.fi[4]; R[2] = t.fi[1];
        R[3] = t.fi[3]; R[4] = t.fi[5]; R[5] = t.fi[2];

        if (visit.find(L) == visit.end()) {
            q.push(mp(L, t.se + 1));
            visit.insert(L);
        }
        if (visit.find(R) == visit.end()) {
            q.push(mp(R, t.se + 1));
            visit.insert(R);
        }
    }
}

int main() {
    for (int i=0; i<6; i++) cin >> a[i];
    for (int i=0; i<6; i++) cin >> b[i];
    cout << solve() << endl;
}
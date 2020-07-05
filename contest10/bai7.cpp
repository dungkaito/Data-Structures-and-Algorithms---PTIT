#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> dsk[100005];

string solve() {
    for (int u=1; u<=n; u++)
        for (int j=0; j<dsk[u].size(); j++)
            if (dsk[u].size() != dsk[dsk[u][j]].size())
                return "NO\n";
    return "YES\n";
}

int main() {
    int t, u, v; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) dsk[i].clear();
        for (int i=1; i<=m; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u);
        }
        cout << solve();
    }
}
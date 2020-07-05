#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector <int> dsk[100005];
vector <int> parent, siz;

int DSU_find(int u) {
    if (parent[u] == u) return u;
    return DSU_find(parent[u]);
}

void DSU_union(int u, int v) {
    // union by size
    int u_root = DSU_find(u);
    int v_root = DSU_find(v);
    if (siz[u_root] < siz[v_root]) {
        parent[u_root] = v_root;
        siz[v_root] += siz[u_root];
        ans = max(ans, siz[v_root]);
    }
    else {
        parent[v_root] = u_root;
        siz[u_root] += siz[v_root];
        ans = max(ans, siz[u_root]);
    }
}

void solve() {
    parent.resize(n+1); siz.resize(n+1);
    for (int i=1; i<=n; i++) parent[i]=i, siz[i]=1;

    ans = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<dsk[i].size(); j++)
            if (DSU_find(i) != DSU_find(dsk[i][j]))
                DSU_union(i, dsk[i][j]);
    cout << ans << endl;
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
        solve();
    }
}
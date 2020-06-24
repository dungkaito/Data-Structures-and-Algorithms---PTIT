#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int>
#define pip pair <int, ii>
#define mp make_pair
#define fi first
#define se second

vector < pip > dsc;
int n, m, parent[105], siz[105];

int DSU_find(int u) {
    if (parent[u] == u) return u;
    return DSU_find(parent[u]);
}

//union by size
void DSU_union(int u, int v) {
    int u_root = DSU_find(u), v_root = DSU_find(v);
    
    if (siz[u_root] <= siz[v_root]) {
        parent[u_root] = v_root;
        siz[v_root] += siz[u_root];
    }
    else {
        parent[v_root] = u_root;
        siz[u_root] += siz[v_root];
    }
}

void kruskal() {
    sort(dsc.begin(), dsc.end());

    // vector <canh> caykhung;
    
    for(int i=1; i<=n; i++) siz[i] = 1, parent[i] = i;

    int ans = 0;
    for (int i=0; i<m; i++) {
        pip tmp = dsc[i];

        int x = tmp.se.fi, y = tmp.se.se;
        if (DSU_find(x) != DSU_find(y)) {
            // caykhung.push_back(dsc[i]);
            DSU_union(x, y);
            ans += tmp.fi;
        }
    }
    cout << ans << endl;
}

int main() {
    int t, a, b, c; cin >> t;
    while (t--) {
        cin >> n >> m;
        dsc.resize(m);
        for (int i=0; i<m; i++) {
            cin >> a >> b >> c;
            dsc[i] = mp(c, mp(a, b));
        }
        kruskal();
    }
}
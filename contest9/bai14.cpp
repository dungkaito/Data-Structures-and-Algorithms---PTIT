#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];

void dfs(int u) {
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) dfs(v);
    }
}

int main() {
    int t, dinh, canh, u, v, Q, x, y; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u);
        }
        cin >> Q;
        while (Q--) {
            cin >> x >> y;
            memset(chuaxet, true, sizeof(chuaxet));
            dfs(x);
            if (chuaxet[y]) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
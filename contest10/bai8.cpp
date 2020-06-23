#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int n, m, u;
vector <int> dsk[1005];
vector <ii> caykhung;
bool chuaxet[1005];

void dfs(int u) {
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) {
            caykhung.push_back(ii(u, v));
            dfs(v);
        }
    }
}

int main() {
    int t, a, b; cin >> t;
    while (t--) {
        cin >> n >> m >> u;
        for (int i=1; i<=n; i++) dsk[i].clear();
        for (int i=1; i<=m; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        }

        caykhung.clear();
        memset(chuaxet, true, sizeof(chuaxet));
        dfs(u);

        if (caykhung.size() == n-1)
            for (int i=0; i<n-1; i++)
                cout << caykhung[i].first << " " << caykhung[i].second << "\n";
        else cout << "-1\n";
    }
}
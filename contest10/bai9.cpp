#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int n, m, u;
vector <int> dsk[1005];
vector <ii> caykhung;
bool chuaxet[1005];

void bfs(int u) {
    queue <int> q;
    q.push(u); chuaxet[u] = false;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<dsk[t].size(); i++) {
            int v = dsk[t][i];
            if (chuaxet[v]) {
                caykhung.push_back(ii(t, v));
                q.push(v);
                chuaxet[v] = false;
            }
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
        bfs(u);

        if (caykhung.size() == n-1)
            for (int i=0; i<n-1; i++)
                cout << caykhung[i].first << " " << caykhung[i].second << "\n";
        else cout << "-1\n";
    }   
}
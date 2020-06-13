#include <bits/stdc++.h>
using namespace std;

int dinh, k;
vector <int> dsk[1005];
bool chuaxet[1005];

void dfs(int u) {
    chuaxet[u] = false;
    k++;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) dfs(v);
    }
}

int main() {
    int t, a, b; cin >> t;
    while (t--) {
        cin >> dinh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=dinh-1; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        } 
        memset(chuaxet, true, sizeof(chuaxet));
        k = 0; dfs(1);
        if (k == dinh) cout << "YES\n";
        else cout << "NO\n";
    }
}
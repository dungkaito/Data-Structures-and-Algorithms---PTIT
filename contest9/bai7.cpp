#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];

void DFS(int u) {
    cout << u << " ";
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) DFS(v);
    }
}

int main() {
    int t, dinh, canh, u, a, b, i, j; cin >> t;
    while (t--) {
        cin >> dinh >> canh >> u;
        
        for (i=1; i<=dinh; i++) dsk[i].clear();

        for (i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
        }

        memset(chuaxet, true, sizeof(chuaxet));
        DFS(u);

        cout << endl;
    }
}
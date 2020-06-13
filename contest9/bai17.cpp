#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];
int k;

void dfs(int u) {
    chuaxet[u] = false;
    k++;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) dfs(v);
    }
}

string kt(int dinh) {
    for (int i=1; i<=dinh; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        k=0;
        dfs(i);
        if (k < dinh) return "NO\n";
    }
    return "YES\n";
}

int main() {
    int t, dinh, canh, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
        }

        cout << kt(dinh);
    }
}
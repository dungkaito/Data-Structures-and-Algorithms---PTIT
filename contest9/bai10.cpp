#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];
int truoc[1005];

void dfs(int u) {
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) {
            truoc[v] = u;
            dfs(v);
        }
    }
}

void inDuongDi(int u, int v) {
    stack <int> res;
    res.push(v);
    while (res.top() != u)
        res.push(truoc[res.top()]);
    while (!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << "\n";
}

int main() {
    int t, dinh, canh, u, v, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh >> u >> v;

        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        }

        memset(chuaxet, true, sizeof(chuaxet));
        dfs(u);

        if (chuaxet[v]) cout << "-1\n";
        else inDuongDi(u, v);
    }
}
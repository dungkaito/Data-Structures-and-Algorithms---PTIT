#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005], check;

void bfs(int a, int parent) {
    int truoc[1005] = {0};
    queue <int> q;
    q.push(a);
    chuaxet[a] = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i=0; i<dsk[u].size(); i++) {
            int v = dsk[u][i];
            if (chuaxet[v]) {
                q.push(v);
                chuaxet[v] = false;
                truoc[v] = u;
            }
            else if (v != truoc[u]) check = true;
        }
    }
}

string chuTrinh(int dinh) {
    for (int i=1; i<=dinh; i++) {
        check = false;
        memset(chuaxet, true, sizeof(chuaxet));
        bfs(i, 0);
        if (check) return "YES\n";
    }
    return "NO\n";
}

int main() {
    int t, dinh, canh, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        }
        cout << chuTrinh(dinh);
    }
}
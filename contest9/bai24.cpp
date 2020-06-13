#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005], check;

void bfs(int u, int t) {
    int truoc[1005] = {0};
    queue <int> q;
    q.push(u);
    chuaxet[u] = false;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<dsk[t].size(); i++) {
            int v = dsk[t][i];
            if (chuaxet[v]) {
                chuaxet[v] = false;
                q.push(v);
                truoc[v] = t;
            }
            else if (v != truoc[t]) check = true;
        }
    }
}

string chuTrinh(int dinh) {
    for (int i=1; i<=dinh; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        check = false;
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
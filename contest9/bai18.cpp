#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];
int k;

void bfs(int u) {
    queue <int> q;
    q.push(u);
    chuaxet[u] = false;
    k++;
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<dsk[t].size(); i++) {
            int v = dsk[t][i];
            if (chuaxet[v]) {
                q.push(v);
                chuaxet[v] = false;
                k++;
            }
        }
    }
}

string kt(int dinh) {
    for (int i=1; i<=dinh; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        k=0;
        bfs(i);
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
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
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<dsk[t].size(); i++) {
            int v = dsk[t][i];
            if (chuaxet[v]) {
                chuaxet[v] = false;
                k++;
                q.push(v);
            }
        }
    }
}

void dinhTru(int dinh) {
    for (int i=1; i<=dinh; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        chuaxet[i] = false;
        k=0;
        if (i==1) bfs(2);
        else bfs(1);
        if (k < dinh-1) cout << i << " ";
    }
    cout << "\n";
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

        dinhTru(dinh);
    }
}
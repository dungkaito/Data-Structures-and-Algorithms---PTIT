#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];
int k;

void bfs(int u) {
    queue <int> q;
    q.push(u);
    k++;
    chuaxet[u] = false;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i=0; i<dsk[t].size(); i++) {
            int v = dsk[t][i];
            if (chuaxet[v]) {
                q.push(v);
                k++;
                chuaxet[v]=false;
            }
        }
    }
}

void canhCau(int dinh) {
    for (int i=1; i<=dinh; i++) {
        for (int j=0; j<dsk[i].size(); j++) {
            if (dsk[i][j] > i) {
                int tmp = dsk[i][j];
                dsk[i].erase(dsk[i].begin() + j);

                memset(chuaxet, true, sizeof(chuaxet));
                k = 0;
                bfs(i);
                if (k < dinh) cout << i << " " << tmp << " ";

                dsk[i].insert(dsk[i].begin() + j, tmp);
            }
        }
    }
    cout << endl;
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
        canhCau(dinh);
    }
}
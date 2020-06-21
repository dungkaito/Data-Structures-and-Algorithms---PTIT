/*open with vscode
dfs tô màu các đỉnh kề nhau màu khác nhau
xong check lại trong adj list
*/
#include <bits/stdc++.h>
using namespace std;

int dinh, canh;
vector <int> dsk[1005];
int color[1005];
bool chuaxet[1005];

void dfs(int u) {
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) {
            color[v] = 1 - color[u];
            dfs(v);
        }
    }
}

int main() {
    int t, u, v, i, j; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (i=1; i<=dinh; i++) dsk[i].clear();
        for (i=1; i<=canh; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u);
        }
        /* color[i]:=
        0: màu 0
        1: màu 1
        */
        memset(color, 0, sizeof(color));
        memset(chuaxet, true, sizeof(chuaxet));
        for (i=1; i<=dinh; i++)
            if (chuaxet[i]) 
                dfs(i);

        bool check = true;
        for (i=1; i<=dinh; i++) {
            for (j=0; j<dsk[i].size(); j++) {
                if (color[i] == color[dsk[i][j]]) {
                    check = false;
                    break;
                }
            }
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}
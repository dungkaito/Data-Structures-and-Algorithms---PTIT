#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second

int a[505][505];
bool chuaxet[505][505];
int dx[8] = {-1,-1,-1,0,0,1,1,1},
    dy[8] = {-1,0,1,-1,1,-1,0,1};

void bfs(int i, int j) {
    queue <ii> q;
    q.push(ii(i,j));
    chuaxet[i][j] = false;
    while (!q.empty()) {
        ii t = q.front(); q.pop();
        for (int i=0; i<8; i++) {
            int x = t.fi + dx[i];
            int y = t.se + dy[i];
            if (a[x][y] == 1 && chuaxet[x][y]) {
                chuaxet[x][y] = false;
                q.push(ii(x,y));
            }
        }
    }
}

int main() {
    int t, n ,m; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                chuaxet[i][j] = true;
            }
        }
        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && chuaxet[i][j]) {
                    bfs(i,j); // danh dau het nhung vi tri co the di
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
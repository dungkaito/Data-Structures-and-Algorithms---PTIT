#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define pip pair<int,pair<int,int>>
#define mp make_pair
#define fi first
#define se second

int a[505][505], n, m, dist[505][505];
int dx[4] = {0,0,-1,1},
    dy[4] = {-1,1,0,0};
    
void solve() {
    queue <ii> q;
    q.push(mp(1, 1));

    dist[1][1] = a[1][1];
    
    while (!q.empty()) {
        ii t = q.front(); q.pop();
        int x = t.fi, y = t.se;
        
        for (int i=0; i<4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            
            if (xx>0 && xx<=n && yy>0 && yy<=m && dist[x][y] + a[xx][yy] < dist[xx][yy]) {
                dist[xx][yy] = dist[x][y] + a[xx][yy];
                q.push(mp(xx, yy));
            }
        }
    }

    cout << dist[n][m] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> a[i][j];
                dist[i][j] = INT_MAX;
            }
        }
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define mp make_pair
#define fi first
#define se second

int n, k, m, cnt;
int fence[105][105][105][105] = {0};//đánh dấu hàng rào
int sheep[105][105] = {0};
int visited[105][105];
int dx[4] = {0, 0, -1, 1},
    dy[4] = {-1, 1, 0, 0};

void bfs(int a, int b) {
    memset(visited, 0, sizeof(visited));
    
    queue <ii> q;
    q.push(mp(a, b));

    visited[a][b] = 1;
    
    cnt=0;
    while (!q.empty()) {
        ii t = q.front(); q.pop();
        int x = t.fi, y = t.se;

        if (sheep[x][y] == 1) cnt++;
        
        for (int i=0; i<4; i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (xx>0 && xx<=n && yy>0 && yy<=n && !fence[x][y][xx][yy] && !visited[xx][yy]) {
                visited[xx][yy] = 1;
                q.push(mp(xx, yy));
            }
        }
    }
}

int main() {
    cin >> n >> k >> m;
    for (int i=0; i<m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        fence[u][v][x][y] = 1;
        fence[x][y][u][v] = 1;
    }
    for (int i=0; i<k; i++) {
        int x, y; cin >> x >> y;
        sheep[x][y] = 1;
    }
    //solve
    int res = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (sheep[i][j] == 1) {
                bfs(i, j);
                // cout << i << "," << j <<" "<< cnt << endl;
                res += (k-cnt);
            }
    cout << res/2 << endl;
    return 0;
}
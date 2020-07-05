#include <bits/stdc++.h>
using namespace std;

/*FLOYD*/
vector<vector<int>> dist(105, vector<int>(105, 1e7));

int main() {
    int n, m, u, v, c;
    cin >> n >> m;
    // init for dp
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> c;
        dist[u][v] = c;
        dist[v][u] = c;
    }
    for (int i=1; i<=n; i++) dist[i][i] = 0;
    // dp
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // res
    cin >> c;
    while (c--) {
        cin >> u >> v;
        cout << dist[u][v] << endl;
    }
    return 0;
}
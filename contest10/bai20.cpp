#include <bits/stdc++.h>
using namespace std;

int dist[105][105];

int main() {
    int t, u, v, i, j, k, n, m; cin >> t;
    while (t--) {
        cin >> n >> m;
        /*---FLOYD---*/
        // init dp
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                dist[i][j] = 1e9;
        
        for (i=1; i<=m; i++) {
            cin >> u >> v;
            dist[u][v] = 1; 
        }
        
        for (i=1; i<=n; i++) dist[i][i] = 0;

        //dp
        for (k=1; k<=n; k++)
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        //ans
        double ans = 0;
        int count = 0;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (dist[i][j] != 1e9 && dist[i][j] != 0) {
                    ans += dist[i][j];
                    count++;
                }
        ans /= count;
        printf("%.2f\n", ans);
    }
}
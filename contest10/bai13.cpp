#include <bits/stdc++.h>
using namespace std;

int dinh, canh, G[1005][1005]; // ma trận trọng số

int chuTrinhAm() {
    /* same as bellman ford - problem15 */
    vector <int> dist(dinh+1, 1e7);
    dist[1] = 0;

    for (int k=1; k<=dinh; k++) {
        bool stop = true;
        for (int i=1; i<=dinh; i++) {
            for (int j=1; j<=dinh; j++) {
                if (dist[i] + G[i][j] < dist[j]) {
                    stop = false;
                    dist[j] = dist[i] + G[i][j];
                    if(k==dinh) return 1;
                }
            }
        }
        if (stop) break;
    }
    return 0;
}

int main() {
    int t, u, v, w; cin >> t;
    while (t--) {
        cin >> dinh >> canh;

        for(int i=1; i<=dinh; i++)
            for (int j=1; j<=dinh; j++)
                G[i][j] = 1e7;

        for (int i=1; i<=canh; i++) {
            cin >> u >> v >> w;
            G[u][v] = w;
        }

        cout << chuTrinhAm() << endl;
    }
}
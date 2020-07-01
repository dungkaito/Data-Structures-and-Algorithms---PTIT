#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF INT_MAX

int dinh, canh;
vector <ii> dsk[1005];

void bellManFord(int start) {
    vector <int> dist(dinh+1, INF);
    dist[start] = 0;

    bool checkCTAm = false;

    //lặp (dinh-1) lần để điền dist cho từng đỉnh,
    //vòng lặp cuối (vòng thứ dinh) là để check chu trình âm
    for (int k=1; k<=dinh; k++) {
        //chọn 1 đỉnh để duyệt tất cả cạnh, k bắt buộc phải đỉnh start đầu tiên
        bool stop = true; // k update thì dừng sớm
        for (int u=1; u<=dinh; u++) {
            if (dist[u] == INF) continue;
            //chọn từng đỉnh kề với u để check dist
            for (int j=0; j<dsk[u].size(); j++) {
                int v = dsk[u][j].se;
                int dist_uv = dsk[u][j].fi;
                
                if (dist_uv + dist[u] < dist[v]) {
                    stop = false;
                    dist[v] = dist[u] + dist_uv;
                    if (k == dinh) checkCTAm = true;
                }
            }
        }
        if (stop) break;
    }
    if (checkCTAm) cout << "-1";
    else {
        for (int i=1; i<=dinh; i++) {
            if (dist[i] == INF) cout << "INFI ";
            else cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int t, start, u, v, w; cin >> t;
    while (t--) {
        cin >> dinh >> canh >> start;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v >> w;
            dsk[u].push_back({w,v});
        }
        bellManFord(start);
    }
}
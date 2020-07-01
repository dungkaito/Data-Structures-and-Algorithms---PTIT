#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define INF INT_MAX

int dinh, canh;
vector <ii> dsk[1005];

void dijkstra(int start) {
    vector <int> cost(dinh+1, INF);
    cost[start] = 0;

    priority_queue < ii, vector <ii>, greater <ii> > pq;
    pq.push(mp(0, start));

    while (!pq.empty()) {
        int u = pq.top().se; pq.pop();
        
        for (int i=0; i<dsk[u].size(); i++) {
            int v = dsk[u][i].se;
            int cost_uv = dsk[u][i].fi;

            if (cost[u] + cost_uv < cost[v]) {
                cost[v] = cost[u] + cost_uv;
                pq.push(mp(cost[v], v));
            }
        }
    }

    for (int i=1; i<=dinh; i++) cout << cost[i] << " ";
    cout << endl;
}

int main() {
    int t, start, u, v, w; cin >> t;
    while (t--) {
        cin >> dinh >> canh >> start;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v >> w;
            dsk[u].push_back({w, v});
            dsk[v].push_back({w, u});
        }
        dijkstra(start);
    }
}
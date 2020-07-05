#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

#define ii pair<int64,int64>
#define mp make_pair
#define fi first
#define se second
#define INF LLONG_MAX

int64 n, m;
vector <ii> dsk[100005];
vector <int64> cost(100005, INF);
vector <int64> dem(100005, 0);
//QHĐ: dem[i] là số cách đi đến i

void dijkstra() {
    cost[1] = 0;
    dem[1] = 1;

    priority_queue <ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, 1));

    while (!pq.empty()) {
        int64 u = pq.top().se;
        int64 du = pq.top().fi;
        pq.pop();
        
        if (du != cost[u]) continue;

        for (int i=0; i<dsk[u].size(); i++) {
            int64 v = dsk[u][i].se;
            int64 cost_uv = dsk[u][i].fi;

            if (cost[u] + cost_uv < cost[v]) {
                cost[v] = cost[u] + cost_uv;
                dem[v] = dem[u];
                pq.push(mp(cost[v], v));
            }
            else if (cost[u] + cost_uv == cost[v])
                dem[v] += dem[u];
        }
    }
    cout << cost[n] << " " << dem[n];
}

int main() {
    int64 u, v, c;
    cin >> n >> m;
    for (int i=1; i<=n; i++) dsk[i].clear();
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> c;
        dsk[u].push_back(mp(c, v));
        dsk[v].push_back(mp(c, u));
    }
    dijkstra();
}
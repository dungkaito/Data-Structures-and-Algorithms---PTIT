/*
idea: www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
dsu method: https://thuytrangcoding.wordpress.com/2017/12/15/graph-mst-kruskal/
*/
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

int dinh, canh;
vector <ii> dsk[105];

void prim() {
    vector <bool> chuaxet(dinh+1, true);// cây khung chưa có đỉnh nào
    
    priority_queue < ii, vector <ii>, greater <ii> > pq;
    
    pq.push({0, 1});

    int ans=0;
    while (!pq.empty()) {
        ii t = pq.top(); pq.pop();
        int u = t.second, min_cost = t.first; 
        
        if (chuaxet[u] == false) continue;
        chuaxet[u] = false; //ghi nhận đỉnh u vào cây khung
        
        ans += min_cost;

        for (int i=0; i<dsk[u].size(); i++) {
            int v = dsk[u][i].second;
            int w_uv = dsk[u][i].first;
            
            if (chuaxet[v])
                pq.push({w_uv, v});
        }
    }
    cout << ans << endl;
}

int main() {
    int t, u, v, w; cin >> t;
    while (t--) {
        cin >> dinh >> canh; 
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v >> w;
            dsk[u].push_back({w, v});
            dsk[v].push_back({w, u});
        }
        prim();
    }
}

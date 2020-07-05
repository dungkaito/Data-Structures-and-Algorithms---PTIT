#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define fi first
#define se second 
#define mp make_pair
#define INF DBL_MAX

int n;
vector <pdd> point;
double ans;
vector <bool> visited;

double dist(int A, int B) {
    return sqrt((point[B].fi-point[A].fi)*(point[B].fi-point[A].fi)+(point[B].se-point[A].se)*(point[B].se-point[A].se));
}

void prim() {
    visited.assign(n+1, false);
    
    priority_queue < pdi, vector<pdi>, greater<pdi> > pq;
    pq.push(mp(0,1));
    
    ans=0;
    while (!pq.empty()) {
        int u = pq.top().se;
        double cost_u = pq.top().fi; // cost_u là độ dài từ điểm trước u đến u (khoảng cách 2 điểm) *line39
        pq.pop();

        if(visited[u]) continue; visited[u] = true;
        
        ans += cost_u;

        for (int i=1; i<=n; i++)
            if (!visited[i])
                pq.push(mp(dist(u, i), i));
    }
    printf("%.6f\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n; point.resize(n);

        for (int i=1; i<=n; i++)
            cin >> point[i].fi >> point[i].se;

        prim();
        
    }
}
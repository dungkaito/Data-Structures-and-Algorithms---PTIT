#include <bits/stdc++.h>
using namespace std;

int dinh, canh;
vector <int> dsk[1005];

string chuTrinh() {
    vector <int> in_degree(dinh+1, 0); // bán bậc vào

    for (int i=1; i<=dinh; i++)
        for (int j=0; j<dsk[i].size(); j++)
            in_degree[dsk[i][j]]++;
    
    queue <int> q;
    for (int i=1; i<=dinh; i++) 
        if (in_degree[i] == 0)
            q.push(i);

    int cnt = 0; // đếm số đỉnh được duyệt

    // vector <int> topo; // result of topological sort

    while (!q.empty()) {
        int u = q.front(); q.pop();
        // topo.push_back(u);
        for (int i=0; i<dsk[u].size(); i++)
            if (--in_degree[dsk[u][i]] == 0)
                q.push(dsk[u][i]);
        cnt++;
    }

    // for (int i=0; i<topo.size(); i++) cout << topo[i] << " ";

    if (cnt != dinh) return "YES\n";
    else return "NO\n";
}

int main() {
    int t, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh; 
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
        }
        cout << chuTrinh();
    }
}
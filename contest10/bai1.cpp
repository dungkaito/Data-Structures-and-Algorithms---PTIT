#include <bits/stdc++.h>
using namespace std;

int dinh, canh, soMau;
vector <int> dsk[15];
int color[15];

bool checkColor(int u, int c) {
    for (int i=0; i<dsk[u].size(); i++)
        if (color[dsk[u][i]] == c) return false;
    return true;
}

bool Try(int u) {
    if (u == dinh + 1) return true;
    for (int i=1; i<=soMau; i++) {
        if (checkColor(u, i)) {
            color[u] = i;
            if (Try(u+1)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int t, u, v; cin >> t;
    while (t--) {  
        cin >> dinh >> canh >> soMau;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u); 
        }
        //color = 0: chưa tô màu
        for (int i=0; i<=dinh; i++) color[i] = 0;
        if (Try(1)) cout << "YES\n";
        else cout << "NO\n";
    }
}
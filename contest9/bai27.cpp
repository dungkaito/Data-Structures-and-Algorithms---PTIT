#include <bits/stdc++.h>
using namespace std;

int dinh, canh, daxet[1005];
vector <int> dsk[1005];
bool check;

/*
mảng daxet:
    0 là chưa duyệt
    1 là đã duyệt qua và đang duyệt
    2 là đã duyệt xong hẳn
*/

void dfs(int u) {
    daxet[u] = 1;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (daxet[v] == 0) dfs(v);
        else if (daxet[v] == 1) check = true;
        daxet[v] = 2;
    }
}

string chuTrinh() {
    for (int i=1; i<=dinh; i++) {
        memset(daxet, 0, sizeof(daxet));
        check = false;
        dfs(i);
        if (check) return "YES\n";
    }
    return "NO\n";
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
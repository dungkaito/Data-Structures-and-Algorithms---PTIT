/*
kiểm tra xem có hoán vị của tập 1->dinh thoả mãn:
    có cạnh giữa 2 số(đỉnh) đứng cạnh nhau trong 1 dãy hoán vị
*/
#include <bits/stdc++.h>
using namespace std;

int dinh, canh;
vector <int> dsk[15];
bool chuaxet[15], check;

void Try(int i, int u) {
    if (i == dinh+1) {
        check = true;
        return;
    }
    for (int j=0; j<dsk[u].size(); j++) {
        int v = dsk[u][j];
        if (chuaxet[v]) {
            chuaxet[v] = false;
            Try(i+1, v);
            chuaxet[v] = true;
        }
    }
}

void hamilton() {
    check = false;
    for (int i=1; i<=dinh; i++) {
        memset(chuaxet, true, sizeof(chuaxet));
        Try(1, i);
        if (check) {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    int t, u, v; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
            dsk[v].push_back(u); 
        }
        hamilton();
    }
}
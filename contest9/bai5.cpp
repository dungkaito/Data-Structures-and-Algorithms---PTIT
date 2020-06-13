#include <bits/stdc++.h>
using namespace std;
vector <int> dsk[1005];
int main() {
    int t, dinh, canh, u, v; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> u >> v;
            dsk[u].push_back(v);
        }
        for (int i=1; i<=dinh; i++) {
            cout << i << ": ";
            for (int j=0; j<dsk[i].size(); j++) {
                cout << dsk[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
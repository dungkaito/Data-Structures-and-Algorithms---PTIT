#include <bits/stdc++.h>
using namespace std;

int dinh, canh;
vector <int> dsk[1005];

int eulerCheck() {
    int dem;
    for (int i=1; i<=dinh; i++) {
        dem = 0;
        for (int j=1; j<=dinh; j++) {
            for (int k=0; k<dsk[j].size(); k++) {
                if (dsk[j][k] == i)
                    dem++;
            }
        }
        if (dem != dsk[i].size()) return 0;
    }
    return 1;
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
        cout << eulerCheck() << endl;
    } 
}
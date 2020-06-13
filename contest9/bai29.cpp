#include <bits/stdc++.h>
using namespace std;

int dinh, canh;
vector <int> dsk[1005];

int eulerCheck() {
    int chan = 0, le = 0;
    for (int i=1; i<=dinh; i++) {
        if (dsk[i].size() % 2 == 0) chan++;
        else le++;
    }
    if (chan == dinh) return 2;
    else if (le == 2) return 1;
    return 0;
}

int main() {
    int t, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        }
        cout << eulerCheck() << endl;
    }
}
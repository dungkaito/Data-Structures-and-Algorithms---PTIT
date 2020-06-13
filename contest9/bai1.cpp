#include <bits/stdc++.h>
using namespace std;
vector <int> dsk[1005];
int main() {
    int t, V, E, a, b; cin >> t;
    while (t--) {
        cin >> V >> E;

        for (int i=0; i<=V; i++)
            dsk[i].clear();

        for (int i=0; i<E; i++) {
            cin >> a >> b; 
            dsk[a].push_back(b);
            dsk[b].push_back(a);
        }

        for (int i=1; i<=V; i++) {
            cout << i << ": ";
            for (int j=0; j<dsk[i].size(); j++)
                cout << dsk[i][j] << " ";
            cout << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
vector <int> dsk[1005];
int main() {
    int n, input; 
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> input;
            if (input == 1) {
                dsk[i].push_back(j);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<dsk[i].size(); j++) {
            cout << dsk[i][j] << " ";
        }
        cout << endl;
    }
}
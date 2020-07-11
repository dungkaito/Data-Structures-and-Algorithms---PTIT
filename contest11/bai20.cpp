#include <bits/stdc++.h>
using namespace std;
int main () {
    int t, n; cin >> t;
    vector <int> a;
    while (t--) {
        cin >> n; a.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];
        
        int check = 1;
        for (int i=1; i<n; i++) {
            if (a[i] <= a[i-1]) {
                check = 0;
                break;
            }
        }
        cout << check << endl;
    }
}
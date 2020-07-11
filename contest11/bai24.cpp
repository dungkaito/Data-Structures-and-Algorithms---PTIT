#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n; cin >> t;
    vector <int> a;
    while (t--) {
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << a[(n-1)/2] << endl;
    }
}
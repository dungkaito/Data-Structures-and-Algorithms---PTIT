#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
    int t, n, i; cin >> t;
    while (t--) {
        cin>>n;
        a.clear(); a.resize(n);
        for (i=0; i<n; i++) cin >> a[i];
        sort (a.begin(), a.end());
        i=1; 
        while (a[i] == a[i-1] && i < n) i++;
        if (i < n) cout << a[0] << " " << a[i] << endl;
        else cout << "-1\n";
    }
}
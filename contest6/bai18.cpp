#include <bits/stdc++.h>
using namespace std;
typedef long long li;
vector<li> merge (vector<li> a, vector<li> b) {
    vector<li> res;
    int i=0, j=0, n=a.size(), m=b.size();
    while (i < n && j < m) {
        if (a[i] <= b[j])
            res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i<n) res.push_back(a[i++]);
    while (j<m) res.push_back(b[j++]);
    return res;
}
int main () {
    int t, n, m;
    vector<li> a,b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.clear(); a.resize(n); 
        b.clear(); b.resize(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector <li> ans = merge(a, b);
        for (int i=0; i<ans.size(); i++) 
            cout << ans[i] <<" ";
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int main() {
    int t, n, a[10005]; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) 
            cin >> a[i];
        sort (a, a + n);
        vector< pair<int, int> > v(n);
        int dem = 1, j=0;
        for (int i=1; i<n; i++) {
            if (a[i] == a[i-1]) 
                dem++;
            else {
                v[j].first = dem;
                v[j].second = a[i-1];
                j++; dem = 1; 
            }
        }
        v[j].first = dem; v[j].second = a[n-1]; j++;
        sort (v.begin(), v.end(), cmp);
        for (int i=0; i<j; i++)
            for (int p=1; p<=v[i].first; p++)
                cout<<v[i].second<<" ";
        cout<<"\n";
    }
}
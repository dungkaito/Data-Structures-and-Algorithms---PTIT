#include <bits/stdc++.h> 
using namespace std;
int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int a[n+5];
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        long long ans=0;
        for (int i=0; i<n; i++) {
            int x = lower_bound(a+i+1, a+n, k+a[i]) - a;
            ans += x-i-1;
        }
        cout << ans << endl;
    }
}
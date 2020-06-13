#include <bits/stdc++.h>
using namespace std;
int count (int a[], int n, int x) {
    int *low = lower_bound(a, a+n, x);
    if (low == (a+n) || *low != x) return -1;
    int *high = upper_bound(low, a+n, x);
    return high - low;
}
int main() {
    int t,x,n,a[1001]; cin>>t;
    while (t--) {
        cin>>n>>x;
        for (int i=0; i<n; i++) cin>>a[i];
        cout<<count(a,n,x)<<endl;
    }
}
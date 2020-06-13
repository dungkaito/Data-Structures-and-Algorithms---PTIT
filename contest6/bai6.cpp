#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main() {
    int t, n; cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n);
        for (int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}
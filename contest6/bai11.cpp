#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, a[1001], i, j; cin>>t;
    while (t--) {
        cin>>n;
        for(i=0; i<n; i++) cin>>a[i];
        int res = a[0] + a[1];
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++) 
                if (abs(a[i]+a[j])<abs(res))
                    res = a[i]+a[j];
        cout<<res<<endl;
    }
}
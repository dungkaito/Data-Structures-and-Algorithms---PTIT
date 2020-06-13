#include <bits/stdc++.h>
using namespace std;
int  A[100001], X;
bool cmp(int a, int b) {
    return abs(X-a) < abs(X-b);
}
int main() {
    int t, n; 
    cin>>t;
    while (t--) {
        cin>>n>>X;
        for (int i=0; i<n; i++) cin>>A[i];
        // sort() k xanh. k gthich được  
        stable_sort(A, A+n, cmp);
        for (int i=0; i<n; i++) cout<<A[i]<<" ";
        cout<<"\n";
    }
}
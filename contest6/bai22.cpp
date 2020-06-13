#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool binSearch(int low, int high, int x) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) return true;
        else if (x < a[mid]) return binSearch(low, mid-1, x);
        else return binSearch(mid+1, high, x);
    }
    return false;
}
int main() {
    int t, n, X;
    cin >> t;
    while (t--) {
        cin >> n >> X;
        for (int i=0; i<n; i++) cin >> a[i];
        if (binSearch(0, n-1,X)) 
            cout<<"1\n";
        else cout<<"-1\n";
    }
    return 0;
}
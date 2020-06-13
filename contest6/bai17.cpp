#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, m;
    long long maxA=INT_MIN, minB=INT_MAX, input;
    cin >> t;
    while (t--) {
        maxA=INT_MIN, minB=INT_MAX;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> input;
            maxA = max(input, maxA);
        } 
        for (int i=0; i<m; i++) {
            cin >> input;
            minB = min(input, minB);
        }
        cout << maxA * minB << endl;
    }
}
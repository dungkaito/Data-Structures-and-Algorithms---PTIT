#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, m, X[MAX], Y[MAX];
// ham nay return so cap (x, từng phần tử trong Y) thoả mãn
int count(int x, int no_of_Y[]) {
    if (x == 0) return 0;
    if (x == 1) return no_of_Y[0];
    int idx = upper_bound(Y, Y+m, x) - Y;
    int res = m-idx;
    res += no_of_Y[0] + no_of_Y[1];
    if (x == 2)
        res -= no_of_Y[3] + no_of_Y[4];
    if (x == 3)
        res += no_of_Y[2];
    return res;
}
int countPairs() {
    int no_of_Y[5] = {0};
    for (int i=0; i<m; i++)
        if (Y[i] < 5) 
            no_of_Y[Y[i]]++;
    sort(Y, Y+m);
    int ans = 0;
    for (int i=0; i<n; i++)
        ans += count(X[i], no_of_Y);
    return ans;
}
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>X[i];
        for (int i=0; i<m; i++) cin>>Y[i];
        cout << countPairs() << endl;
    }
}
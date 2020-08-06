/* open with vscode
P(n)
nếu n<k -> P(n) = 0;
nếu n>=k -> P(n) = n*P(n-1)/(n-k);
EDITED: k xanh, chắc idea sai, k bt làm dp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long li;
int n, k, M=1e9+7;
li solve() {
    li res=1;
    if (n<k) res=0;
    for (int i=n-k+1; i<=n; i++) 
        res = res * i % M;
    return res;
}
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n>>k;
        cout<<solve()<<endl;
    }
}
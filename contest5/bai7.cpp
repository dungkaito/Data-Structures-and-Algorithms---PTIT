/* open with vscode
F[100001]
cần tìm F[n]
bước tối đa k bước

tìm số cách bước từ bậc thứ 1 đến bậc thứ k
    F[1] = 1
    for i=2 to k
        for j = 1 to i
            F[i] += F[j]
        F[i]+=1 // bước 1 phát i bước để từ bậc 1->bậc i
    vd k=4: F1 = 1
            F2 = 1 + 1 = 2
            F3 = 1 + 2 + 1 = 4
            F4 = 1 + 2 + 4 + 1 = 8

tìm số cách bước từ bậc thứ k+1 đến bậc thứ n
    F[i] = F[i-k] + F[i-k+1] + ... + F[i-1]
EDITED: chưa tối ưu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long li;
int M = 1e9+7, n, k;
li F[100001];
li solve() {
    int i, j;
    memset(F, 0, sizeof(F));
    F[1] = 1;
    for(i=2; i<=k; i++) {
        for (j=1; j<i; j++)
            F[i] = (F[i] + F[j])%M;
        F[i] += 1;
    }
    for(i=k+1; i<=n; i++)
        for(j=i-1; j>=i-k; j--)
            F[i] = (F[i] + F[j])%M;
    return F[n];
}
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n>>k;
        cout<<solve()<<endl;
    }
}
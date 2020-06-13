/* open with vscode to read
F[i][j] là số lượng các số có i chữ số, tổng các chữ
số bằng j
j=0=>F=0
i=0->F=0
i=1&&j<10->F=1
for i=2 to 100
    for j=1 to 50000
        for x=0 to j
            F[i][j] = F[i][j] + F[i-1][j-x]
        if (i==2) F[i][j]--; //trừ trường hợp số 0 đầu tiên
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long li;
int M = 1e9+7;
li F[101][50001]={0};
void init() {
    int i, j;
    for(i=0; i<10; i++) F[1][i] = 1;
    for(i=2; i<=100; i++) {
        for(j=1; j<=50000; j++) {
            for (int x=0; x<=j && x<10; x++) {
                if (i==2 && x==j) continue;
                F[i][j] = (F[i][j] + F[i-1][j-x])%M;
            }
        }
    }
}
int main() {
    int t, n, k; cin>>t;
    init();
    while (t--) {
        cin>>n>>k;
        cout<<F[n][k]<<endl;
    }
}
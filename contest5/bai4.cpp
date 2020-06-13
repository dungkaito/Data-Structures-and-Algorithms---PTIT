/* open with vscode to read
dãy con dài nhất có tổng chia hết cho k
10 3
2 3 5 7 9 6 12 7 11 15
output: 9
F(n,k) =Fij là độ dài dãy con dài nhất có tổng%k=j của dãy {a1, a2, a3...ai}
cần tìm F[n][0]
tại thời điểm a1,a2,...ai-1,ai
có 2 khả năng (hơi giống bài cái túi)
    note:(để ý định nghĩa mảng F line 6)
    nếu không lấy a[i]: Fij=Fi-1,j 
    nếu lấy a[i] : Fij=F(i-1,(J-ai)%k) + 1 (với J%k=j hay J là tổng dãy con được chọn tính đến a(i-1))
        áp dụng (a-b)%m = (a%m - b%m + m)%m
        ta có Fij = F(i-1,(J%k-a[i]%k+k)%k)     + 1
                  = F(i-1,(j-a[i]%k+k)%k)    + 1
base case: n=0: F=0.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int A[], int n, int k) {
    int F[n+1][k], i, j;
    F[0][0] = 0;
    for (i=1; i<k; i++) F[0][i] = INT_MIN;
    for (i=1; i<=n; i++) {
        for (j=0; j<k; j++) {
            F[i][j] = max(F[i-1][j], F[i-1][(j - A[i]%k + k)%k] + 1);
            // cout<<F[i][j]<<" ";
        }
        // cout<<endl;
    }
    return F[n][0];
}
int main() {
    int t, n, k, A[1001]; cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=1; i<=n; i++) cin>>A[i];
        cout<<solve(A, n, k)<<endl;
    }
}
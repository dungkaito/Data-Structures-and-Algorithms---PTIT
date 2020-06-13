/* open with vscode to read
input đề bài: A[n][m] n,m<=500
1 1 1
1 1 1
1 1 1
S[i][j] là kích thước hình vuông "1" lớn nhất có A[i][j] là điểm 
dưới cùng bên phải của hình vuông đấy
khởi tạo: các giá trị nằm trên hàng đầu và cột đầu của S sẽ bằng A
nếu Aij = 0: S = 0
nếu Aij = 1: S = min(Sij-1, Si-1j, Si-1j-1) + 1
ví dụ S[][]:
1 1 1
1 2 2
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int A[][501], int n, int m) {
    int Size[n][m], ans=0, i, j;
    for (i=0; i<n; i++) Size[i][0] = A[i][0];
    for (j=0; j<m; j++) Size[0][j] = A[0][j];
    for (i=1; i<n; i++)
        for (j=1; j<m; j++) {
            if (A[i][j] == 0) Size[i][j] = 0;
            else Size[i][j] = min(Size[i][j-1], min(Size[i-1][j], Size[i-1][j-1])) + 1;
            ans = max(ans, Size[i][j]);
        }
    return ans;
}
int main() {
    int t, m, n, A[501][501]; cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++)
                cin>>A[i][j];
        cout<<solve(A, n, m)<<endl;
    }
}
/* open with vscode
Fij là tổng điểm nhỏ nhất đi từ A11->Aij
i=j=1 F=Aij
i=1 j!=1 : F=vị trí bên trái +Aij
j=1 i!=1 : F=vị trí bên trên +Aij
Fij = min(F cua 3 vị trí có thể đến Aij) + Aij
-> kết quá: F[N][M]
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, m; cin>>t;
    while (t--) {
        cin>>n>>m;
        int A[n+1][m+1];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                cin>>A[i][j];
        int F[n+1][m+1];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (i==1 && j==1) F[i][j] = A[i][j];
                else if (i==1) F[i][j] = F[i][j-1] + A[i][j];
                else if (j==1) F[i][j] = F[i-1][j] + A[i][j];
                else F[i][j] = min(F[i-1][j], min(F[i][j-1], F[i-1][j-1])) + A[i][j];
        cout<<F[n][m]<<endl;
    }
}
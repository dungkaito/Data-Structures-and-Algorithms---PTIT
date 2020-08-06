/* open with vscode
-struct cặp số a,b, a<b
-phải sort mảng đầu vào tăng dần theo a để tối ưu
-tìm dãy con tăng dài nhất theo cách so sánh của đề bài
*/
#include <bits/stdc++.h>
using namespace std;
struct CapSo {
    int a, b;
};
bool cmp(CapSo x, CapSo y) {
    return x.a<y.a;
}
int solve(CapSo X[], int n) {
    int F[101]; int kq=F[0]=1;
    for (int i=1; i<n; i++) {
        F[i]=1;
        for (int j=0; j<i; j++)
            if (X[j].b<X[i].a && F[i]<F[j]+1)
                F[i] = F[j] + 1;
        kq = max(kq,F[i]);
    }
    return kq; 
}
int main() {
    int t, n; cin>>t;
    CapSo X[101];
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) 
            cin>>X[i].a>>X[i].b;
        sort(X, X+n, cmp);
        cout<<solve(X, n)<<endl;
    }
}
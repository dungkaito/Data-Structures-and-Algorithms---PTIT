/* open with vscode to read
dãy bi-tonic là dãy có các phần tử tăng dần xong giảm dần
tìm max sum tất cả dãy con bitonic của mảng A
solution:
tạo 2 mảng: tongTang[i] lưu tổng lớn nhất của dãy con tăng dần kết thúc ở A[i]
            tongGiam[i] lưu tổng lớn nhất của dãy con giảm dần bắt đầu từ A[i]
Kết quả: tongTang[i]+tongGiam[i]-A[i] <- tìm max tất cả các index
tính tongTang: tổng lớn nhất của dãy con tăng dần kết thúc ở A[i]
for i:=0 to n-1 :
    tongTang[i] = a[i] : ít nhất cũng bằng a[i]
    tìm tiếp các phần tử nhỏ hơn a[i] phía trước
    for j:=0 to i-1
        nếu a[j] < a[i]
            nếu Tj+ai > Ti thì mới cậP nhật Ti 
            tongTang[i] = max(tongTang[i], tongTang[j]+a[i])
tính tongGiam tương tự, lặp từ cuối về.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int A[], int n) {
    int tongTang[n], tongGiam[n], i, j;
    for (i=0; i<n; i++) {
        tongTang[i] = A[i];
        tongGiam[i] = A[i];
    }
    for (i=1; i<n; i++)
        for (j=0; j<i; j++)
            if (A[j]<A[i] && tongTang[i]<tongTang[j]+A[i])
                tongTang[i] = tongTang[j]+A[i];
    for (i=n-2; i>=0; i--)
        for (j=n-1; j>i; j--)
            if (A[j]<A[i] && tongGiam[i]<tongGiam[j]+A[i])
                tongGiam[i] = tongGiam[j]+A[i];
    int ans=INT_MIN;
    for (i=0; i<n; i++) 
        ans = max(ans, tongTang[i]+tongGiam[i]-A[i]);
    return ans;
}
int main() {
    int t, n, A[101]; cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>A[i];
        cout<<solve(A,n)<<endl;
    }
}
/*open with vscode
sort mảng đầu vào
duyệt:
    phần từ đầu tiên bên trái khác lúc đầu và
    phần từ đầu tiên bên phải khác lúc đầu
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int n, a[MAX], tmp[MAX];
int main() {
    int t; cin>>t;
    while (t--) {
        int l, r, i;
        cin>>n;
        for (i=0; i<n; i++) {
            cin>>a[i];
            tmp[i] = a[i];
        }
        sort(tmp, tmp+n);
        l=0;
        while (a[l] == tmp[l]) l++;
        r=n-1;
        while (a[r] == tmp[r]) r--;
        cout<<l+1<<" "<<r+1<<"\n";
    }
}
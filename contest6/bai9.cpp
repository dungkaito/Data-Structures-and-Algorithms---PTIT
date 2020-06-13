/*open with vscode
tìm các cặp có tổng = k
sort mảng tăng dần
ans=0
duyệt i từ đầu 
    tìm k-a[i] xem có trong i+1 -> n-1 không. 
        hàm search trả về index
    if (index = -1) continue;
    tìm từ i -> n-1 xem có bao nhiêu a[i] = aindex
        nếu a[i]=a[index]
            ans+=1
*/
#include <bits/stdc++.h>
using namespace std;
int n, k, a[101];
int binarySearch(int low, int high, int x){
    if (low <= high) {
        int mid = (low+high)/2;
        if (x == a[mid]) return mid;
        else if (x<a[mid]) return binarySearch(low, mid-1, x);
        else return binarySearch(mid+1, high, x);
    }
    return -1;
}
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n);
        int ans=0;
        for (int i=0; i<n-1; i++) {
            int index = binarySearch(i+1, n-1, k-a[i]);
            if (index == -1) continue;
            for (int j=i+1; j<n; j++)
                if (a[j] == a[index]) 
                    ans+=1;
        }
        cout<<ans<<endl;
    }
}
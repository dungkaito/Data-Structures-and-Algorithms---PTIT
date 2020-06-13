/*open with vscode
sàng số nguyên tố < 1000000 lưu vào mảng snt
check=0
for i=0 đến n
    tìm xem có n-snt(i) trong snt:i+1 đến n
    nếu có in ra snti, n-snt ; check=1; break;
nếu check vẫn =0 in ra -1;
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n; vector<int> snt;
void sangSNT() {
    vector<bool> mark(MAX+1, true);
    for (int i=2; i*i<=MAX; i++) {
        if (mark[i]) {
            for (int j=i*i; j<=MAX; j+=i)
                mark[j] = false;
        }
    }
    for (int i=2; i<=MAX; i++)
        if (mark[i])
            snt.push_back(i);
}
bool binarySearch (int low, int high, int x){
    if (low<=high){
        int mid = (low + high) / 2;
        if (snt[mid] == x) return true;
        else if (x < snt[mid]) return binarySearch(low, mid-1, x);
        else return binarySearch(mid+1, high, x);    
    }
    return false;
}
int main(){
    sangSNT();
    // for (int i=0; i<snt.size(); i++) 
    //     cout<<snt[i]<<" ";
    // cout <<endl;
    // cout<<snt[snt.size()-1];
    // cout<<snt.size();
    int t; cin>>t;
    while (t--) {
        cin >> n;
        int check = 0;
        int i=0;
        while (snt[i]<=n) {
            if (binarySearch(i, snt.size()-1, n-snt[i])){
                cout<<snt[i]<<" "<<n-snt[i]<<endl;
                check=1;
                break;
            }
            i++;
        }
        if (check==0) cout<<-1<<endl;
    }
}
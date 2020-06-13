#include <bits/stdc++.h>
using namespace std;
typedef long long li;
int main() {
    int t, n; cin>>t;
    li input;
    while (t--) {
        cin>>n;
        int danhDau[10]={0};
        for (int i=0; i<n; i++) {
            cin>>input;
            while (input > 0) {
                danhDau[input%10] = 1;
                input/=10;
            }
        }
        for (int i=0; i<10; i++) {
            if(danhDau[i]) cout<<i<<" ";
        }
        cout<<"\n";
    }
}
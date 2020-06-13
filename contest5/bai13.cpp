/* open with vscode to read
U: 1 2 3 4 5 6 8 9 10 12 15
các số U chỉ chia hết cho 2 hoặc 3 hoặc 5
chia U thành 3 mảng con:
các số chia hết cho 2: 2 4 5 6 8...
                       1x2 2x2 3x2
các số chia hết cho 3: 3 6 9 12....
                       1x3 2x3 4x3
các số chia hết cho 5: 5 10 15 20...
trộn lại tìm số U thứ n.
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uli;
// uli ugly[10001];
/*
void tinhUgly() {
    ugly[0] = 1;
    int i2=0, i3=0, i5=0;
    uli next_ugly_no = 1;
    uli next_multiple_of_2 = ugly[i2]*2;
    uli next_multiple_of_3 = ugly[i3]*3;
    uli next_multiple_of_5 = ugly[i5]*5;
    for(int i=1; i<10000; i++) {
        next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2++;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3++;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5++;
            next_multiple_of_5 = ugly[i5]*5;
        }
    }
}
*/
long long solve(int n) {
    long long ugly[n];
    ugly[0] = 1;
    int i2=0, i3=0, i5=0;
    for (int i=1; i<n; i++) {
        ugly[i] = min(ugly[i2]*2, min(ugly[i3]*3, ugly[i5]*5));
        if (ugly[i] == ugly[i2]*2) i2++;
        if (ugly[i] == ugly[i3]*3) i3++;
        if (ugly[i] == ugly[i5]*5) i5++;
    }
    return ugly[n-1];
}
int main() {
    int t, n; cin>>t;
    // tinhUgly();
    while (t--) {
        cin>>n; 
        // cout<<ugly[n-1]<<endl;
        cout<<solve(n)<<endl;
    }
}
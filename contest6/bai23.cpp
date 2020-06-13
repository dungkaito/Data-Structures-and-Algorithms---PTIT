#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, a, b; cin >> t;
    while (t--) {
        cin >> n; a = 0; b = 0;
        int check = 0, ans = 0;
        for (int i=0; i<n-1; i++) {
            cin >> b;
            if (check == 0) {
                if (b != a+1) {
                    ans = a+1;
                    check = 1;
                }
                a = b;
            }
        }
        cout<<ans<<endl;
    }
}
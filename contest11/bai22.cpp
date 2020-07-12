#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n; cin >> t;
    vector <int> pre;
    while (t--) {
        cin >> n; pre.resize(n);
        for (int i=0; i<n; i++) cin >> pre[i];
        
        stack <int> s;
        bool found;
        int leaf=0;
        for (int i=0; i<n-1; i++) {
            found = false;
            if (pre[i] > pre[i+1]) s.push(pre[i]);
            else {
                while (!s.empty()) {
                    if (pre[i+1] > s.top()) {
                        s.pop();
                        found = true;
                    }
                    else break;
                }
                if (found) leaf++;
            }
        }
        leaf++;
        cout << n - leaf << endl;
    }
}
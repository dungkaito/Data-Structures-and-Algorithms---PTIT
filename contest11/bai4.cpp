#include <bits/stdc++.h>
using namespace std;

int pre[1005];

void postOrder(int l, int r) {
    if (l > r) return;
    int i = l + 1;
    while (i <= r && pre[i] < pre[l]) i++;
    postOrder(l + 1, i - 1);
    postOrder(i, r);
    cout << pre[l] << " ";
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> pre[i];
        postOrder(0, n-1);
        cout << endl;
    }
}
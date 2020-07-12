#include <bits/stdc++.h>
using namespace std;

vector <int> pre;

void postOrder(int l, int r) {
    if (l > r) return;
    int i = l + 1;
    while (i <= r && pre[l] > pre[i]) i++;
    postOrder(l + 1, i - 1);// left sub tree
    postOrder(i, r); // right subtree
    cout << pre[l] << " "; // data
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n; pre.resize(n);
        for (int i=0; i<n; i++) cin >> pre[i];
        postOrder(0, n-1);
        cout << endl;
    }
}
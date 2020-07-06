#include <bits/stdc++.h>
using namespace std;

int search(int a[], int x, int n) {
    for (int i=0; i<n; i++)
        if (a[i] == x) return i;
    return -1;
}

void printPostOrder(int in[], int pre[], int n) {
    int root = search(in, pre[0], n); //find root index
    if (root > 0)
        printPostOrder(in, pre+1, root);
    if (root < n-1)
        printPostOrder(in+root+1, pre+root+1, n-root-1);
    cout << pre[0] << " ";
}

int main() {
    int t, n, in[1005], pre[1005]; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> in[i];
        for (int i=0; i<n; i++) cin >> pre[i];
        printPostOrder(in, pre, n);
        cout << endl;
    }
}
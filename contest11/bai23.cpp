#include <bits/stdc++.h>
using namespace std;

int ans = -1;

int search(int val, int a[], int st, int en) {
    if (st > en) return -1;
    int mid = (st+en)/2;
    if (a[mid] == val) return mid;
    else if (a[mid] > val) return search(val,a,st,mid-1);
    else return search(val,a,mid+1,en);
}

void height(int pre[], int &ind, int in[], int st, int en, int level) {
    if (st > en) return;
    ans = max(ans, level);
    int rootIndex = search(pre[ind], in, st, en);
    ind++;
    height(pre, ind, in, st, rootIndex-1, level + 1);
    height(pre, ind, in, rootIndex+1, en, level+1);
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        ans = -1;
        cin >> n;
        int pre[n], in[n];
        for(int i=0; i<n; i++) {
            cin >> pre[i];
            in[i] = pre[i];
        }
        sort(in, in + n);
        int ind = 0;
        height(pre, ind, in, 0, n-1, 0);
        cout << ans << endl;
    }
}
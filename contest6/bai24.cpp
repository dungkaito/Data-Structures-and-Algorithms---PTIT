/*#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, x; cin >> t;
    while (t--) {
        cin >> n >> x;
        int ans = -1, input;
        for (int i=1; i<=n; i++) {
            cin >> input;
            if (input == x) ans = i;
        }
        cout << ans << endl;
    }
}*/
#include <bits/stdc++.h>
using namespace std;
int search (vector<int> a, int l, int h, int key) {
    if (l > h) return -1;
    int mid = (l + h) / 2;
    if (a[mid] == key) return mid;
    if (a[l] <= a[mid]) {
        if (key >= a[l] && key <= a[mid])
            return search(a, l, mid-1, key);
        return search(a, mid+1, h, key);
    }
    if (key >= a[mid] && key <= a[h])
        return search(a, mid+1, h, key);
    return search(a, l, mid-1, key);
}
int main() {
    int t, n, x; cin >> t;
    vector<int> a;
    while (t--) {
        cin >> n >> x;
        a.clear(); a.resize(n);
        for (int i=0; i<n; i++) cin>>a[i];
        cout << search(a, 0, n-1, x) + 1 << endl;
    }
}
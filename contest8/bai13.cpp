#include <bits/stdc++.h>
using namespace std;

bool check(int k) {
    if (k == 0) return true;
    priority_queue <int> pq;
    while (k>0) {
        pq.push(k % 10);
        k /= 10;
    }
    if (pq.top() > 5) return false;
    while (pq.size() > 1) {
        int top1 = pq.top(); pq.pop();
        if (top1 == pq.top())
            return false; 
    }
    return true;
}

int main() {
    vector <int> v;
    for (int i=0; i<=100000; i++)
        if (check(i))
            v.push_back(i);

    int t, L, R; cin >> t;
    while (t--) {
        cin >> L >> R;
        int low = lower_bound(v.begin(), v.end(), L) - v.begin();
        int up = upper_bound(v.begin(), v.end(), R) - v.begin();
        cout << up - low << endl;
        // int ans = 0;
        // for (int x=L; x<=R; x++)
        //     if (check(x))
        //         ans++;
        // cout << ans << endl;
    }
}
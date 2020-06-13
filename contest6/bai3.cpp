/* open with vscode to read
0 1 2 3 4 index truoc sort
5 1 4 2 8 
1 2 4 5 8 sorted
1 3 2 0 4 index sau sort
tạo 1 vector pair v: first = a[i], second = i
sort v theo first tăng dần
duyệt i từ đầu đến cuối v
    nếu v[i].second = i: đúng vị trí ban đầu khi chưa sort rồi.
        continue;
    nếu v[i].second(índex sau sorted) khác i(index trước sort)
        swap v[ v[i].second ] , v[i] 
    nếu sau khi swap mà v[i].second vẫn khác i
        i--; để duyệt lại vị trí hiện tại (đổi chỗ cho đến khi nào đúng vị trí ban đầu khi chưa sort thì thôi).
    ans++; 1 lần đổi chỗ được tính
// cách trên k xanh
làm cách cycle trên geek
*/
#include <bits/stdc++.h>
using namespace std;
int n; vector< pair<int, int> > A;
// void DFS(int z, vector<bool> &vis, vector<vector<int>> &adj, int &siz) {
//     siz = siz + 1; vis[z] = true;
//     for (auto t: adj[z]) {
//         if (vis[t]) continue;
//         DFS(t, vis, adj, siz);
//     }
// }
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n; 
        A.clear(); A.resize(n);
        for (int i=0; i<n; i++){
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(A.begin(), A.end());
        // vector<vector<int>> adj(n);
        // for (int i=0; i<n ;i++) {
        //     adj[i].push_back(A[i].second);
        //     adj[A[i].second].push_back(i);
        // }
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (vis[i] || A[i].second == i)
                continue;
            int j = i, cycle_size = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = A[j].second;
                cycle_size += 1;
            }
            if (cycle_size > 0) 
                ans += cycle_size - 1;
        }
        // for (int i=0; i<n; i++) {
        //     if (vis[i]) continue;
        //     int siz = 0; DFS(i, vis, adj, siz);
        //     ans += siz - 1;
        // }
        cout << ans << endl;
    }
}

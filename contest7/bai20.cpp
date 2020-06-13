/*open with vscode
a[] = 4 5 2 25
stack<int> st;
vector ans
duyệt i ngược từ phải -> trái mảng a
    while !st.empty && a[i] >= st.top :
        st.pop();
    if (st.empty) {
        ans.push -1
        st.push(a[i])
    } 
    else {
        ans.push(st.top);
        st.push(a[i]);
    }
reverse ans
cout ans
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        a.clear(); a.resize(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<int> ans;
        stack <int> st;
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && a[i] >= st.top()) 
                st.pop();
            if (st.empty()) {
                ans.push_back(-1);
                st.push(a[i]);
            }
            else {
                ans.push_back(st.top());
                st.push(a[i]);
            }
        }
        for (int i=ans.size()-1; i>=0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}
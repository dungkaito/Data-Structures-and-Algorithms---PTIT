/*open with vscode
tìm mảng G - next greater của từng element in A
tìm mảng S - next smaller của từng element in A
ans = S[G[i]] với i = 0 -> n-1
*note mảng G lưu index chứ không phải value
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> A, G, S;

void nextGreater() {
    G.clear(); G.resize(n);
    stack <int> st; //index
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && A[i] >= A[st.top()])
            st.pop();
        if (st.empty()) {
            G[i] = -1;
            st.push(i);
        }
        else {
            G[i] = st.top();
            st.push(i);
        }
    }
}

void rightSmaller() {
    S.clear(); S.resize(n);
    stack <int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && A[i] <= st.top())
            st.pop();
        if (st.empty()) {
            S[i] = -1;
            st.push(A[i]);
        }
        else {
            S[i] = st.top();
            st.push(A[i]);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n; A.clear(); A.resize(n);
        for (int i=0; i<n; i++)
            cin >> A[i];
        
        nextGreater();
        rightSmaller();
        
        for (int i=0; i<n; i++)
            if (G[i] == -1) cout << "-1 ";
            else cout << S[G[i]] << " ";
        cout << "\n";
    }
}
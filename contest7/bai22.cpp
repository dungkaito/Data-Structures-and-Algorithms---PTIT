/*open with vscode
mảng L - lưu index left smaller của từng element in H
mảng R - lưu index right smaller của từng element in H
for i:= 0->n-1
    FOPT = max(FOPT, H[i]*(R[i]-L[i]-1))
diện tích lớn nhất : FOPT
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int n;
vector <int64> H, L, R;

void leftSmaller() {
    L.clear(); L.resize(n);
    stack <int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && H[i] <= H[st.top()])
            st.pop();
        L[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
}

void rightSmaller() {
    R.clear(); R.resize(n);
    stack <int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && H[i] <= H[st.top()])
            st.pop();
        R[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n; H.clear(); H.resize(n);
        for (int i=0; i<n; i++)
            cin >> H[i];

        leftSmaller();
        rightSmaller();

        // for (int i=0; i<n; i++) 
        //     cout << R[i] << " ";
        // cout <<endl;

        // for (int i=0; i<n; i++) 
        //     cout << L[i] << " ";
        // cout <<endl;

        int64 FOPT = INT_MIN;
        for (int i=0; i<n; i++) 
            FOPT = max(FOPT, H[i]*(R[i]-L[i]-1));
        cout << FOPT << endl;
    }
}
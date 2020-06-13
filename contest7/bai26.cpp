#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> A, B;

void nhipChungKhoan() {
    B.clear(); B.resize(n);
    stack <int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && A[i] >= A[st.top()])
            st.pop();
        if (st.empty()) B[i] = i + 1;
        else B[i] = i - st.top();
        st.push(i);
    }
}

int main() {
    cin >> n; A.clear(); A.resize(n);
    for (int i=0; i<n; i++)
        cin >> A[i];
    
    nhipChungKhoan();

    for (int i=0; i<n; i++)
        cout << B[i] << " ";
    cout << endl;
}
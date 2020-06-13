/* open with vscode to read
F[i] là tổng lớn nhất của dãy con không kề nhau của dãy A0 A1...Ai
-> cần tính F[n-1]
nhận xét: F[0]->F[i] là dãy tăng dần
F[i] sẽ bằng F[i-1] hoặc F[i-2]+A[i]. vì F[i-3]... luôn bé hơn F[i-2]
công thức QHD: 
    F[0] = A[0]
    F[1] = max(A[0], A[1])
    F[i] = max(F[i-1], F[i-2]+A[i]);
5 5 10 100 10  5
5 5 15 105 105 110
3 2 7 10
3 3 10 13
3 7 2 10
3 7 7 17
*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A, int n) {
    int F[n];
    F[0] = A[0]; F[1] = max(A[0], A[1]);
    for (int i=2; i<n; i++)
        F[i] = max(F[i-1], F[i-2] + A[i]);
    return F[n-1];
}
int main() {
    int t, n; cin>>t;
    vector<int> A;
    while (t--) {
        cin>>n;
        int input; A.clear();
        for (int i=0; i<n; i++) {
            cin>>input;
            A.push_back(input);
        }
        cout<<solve(A, n)<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, m, A[MAX], B[MAX]; 
int main() {
    int t, i, j; cin>>t;
    while (t--) {
        cin>>n>>m;
        for (i=0; i<n; i++) cin>>A[i];
        for (i=0; i<m; i++) cin>>B[i];
        sort(A, A+n); sort(B, B+m);
        vector<int> Union, Intersection;
        i=0; j=0;
        while (i<n && j<m)
            if (A[i] < B[j])
                Union.push_back(A[i++]);
            else if (A[i] > B[j])
                Union.push_back(B[j++]);
            else Intersection.push_back(A[i++]);
        while (i<n)
            Union.push_back(A[i++]);
        while (j<m) 
            Union.push_back(B[j++]);
        for (i=0; i<Union.size(); i++) cout<<Union[i]<<" ";
        cout<<endl;
        for (i=0; i<Intersection.size(); i++) cout<<Intersection[i]<<" ";
        cout<<endl;
    }
}
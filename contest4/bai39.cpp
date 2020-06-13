#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i=0; i<int(n); i++)

const int MAX=10000001;

typedef long long ll;

ll a[MAX], b[MAX];

int solve (int i) {
	if (a[i] != b[i]) return i+1;
	return solve(i+1);
}

int main() {
	int t,n; cin>>t;
	while (t--) {
		cin>>n;
		forn(i,n) cin>>a[i];
		forn(i,n-1) cin>>b[i];
		cout<<solve(0)<<endl;
	}
}

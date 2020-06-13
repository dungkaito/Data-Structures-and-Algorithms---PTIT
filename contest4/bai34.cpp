#include<bits/stdc++.h>
#define forn(i, n) for (int i=0; i<int(n); i++)
using namespace std;
typedef long long li;
int main() {
	int t, m, n, p[101], q[101]; cin>>t;
	while (t--) {
		cin>>m>>n;
		forn(i,m) cin>>p[i];
		forn(i,n) cin>>q[i];
		int size=m+n-1;
		li r[size];
		forn(i,size) r[i]=0;
		forn(i,m) forn(j,n)
			r[i+j] += p[i]*q[j];
		forn(i,size) cout<<r[i]<<" ";
		cout<<"\n";
	}
	return 0;
}

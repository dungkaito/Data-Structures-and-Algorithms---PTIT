#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0; i<int(n); i++)

typedef long long ll;

int A[1000001], B[1000001];

int search(int a, int b, int k) {
	if (A[a] < B[b]) {
		k--;
		if (k==0) return A[a];
		return search(a+1, b, k);
	}
	else {
		k--;
		if (k==0) return B[b];
		return search(a, b+1, k);
	}
}

int main() {
	int t,m,n,k; cin>>t;
	while (t--) {
		cin>>m>>n>>k;
		forn(i,m) cin>>A[i];
		forn(i,n) cin>>B[i];
		cout<<search(0,0,k)<<endl;
	}
}

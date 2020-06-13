#include<bits/stdc++.h>
using namespace std;
long long C(int k, int n) {
	long long toHop[k+1][n+1];
	for(int i=0; i<=k; i++) {
		for(int j=i ;j<=n; j++) {
			if(i==0 || i==j) toHop[i][j]=1;
			else if(i==1 || i==j-1) toHop[i][j]=j;
			else toHop[i][j] = toHop[i-1][j-1]+toHop[i][j-1];
		}
	}
	return toHop[k][n];
}
int main() {
	int t,m,n,x; cin>>t;
	while(t--) {
		cin>>m>>n;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++) cin>>x;
		cout<<C(n-1,m+n-2)<<endl;
	}
}

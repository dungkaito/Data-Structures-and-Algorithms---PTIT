#include<bits/stdc++.h>
using namespace std;
int F[1001][1001], N, V, A[1001], C[1001];
int solve() {
	int i,j;
	for(i=0; i<=V; i++) F[0][i] = 0;
	for (i=1; i<=N; i++) {
		for (j=1; j<=V; j++) {
			if (j >= A[i]) F[i][j] = max(F[i-1][j-A[i]]+C[i], F[i-1][j]);
			else F[i][j] = F[i-1][j];
		}
	}
	return F[N][V];
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>N>>V;
		for(int i=1; i<=N; i++) cin>>A[i];
		for(int i=1; i<=N; i++) cin>>C[i];
		cout<<solve()<<endl;
	}
}

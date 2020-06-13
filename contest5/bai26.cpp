#include<bits/stdc++.h>
using namespace std;
int w[101], F[101][25001];
int solve(int C, int N) {
	int i,j;
	for (i=0; i<=C; i++) F[0][i] = 0;
	for (i=1; i<=N; i++) {
		for (j=1; j<=C; j++) {
			if (w[i]<=j) F[i][j] = max(F[i-1][j-w[i]] + w[i], F[i-1][j]);
			else F[i][j] = F[i-1][j];
		}
	}
	return F[N][C];
}
int main() {
	int C, N;
	cin>>C>>N;
	for (int i=1; i<=N; i++) cin>>w[i];
	cout<<solve(C, N)<<endl;
	return 0;
}

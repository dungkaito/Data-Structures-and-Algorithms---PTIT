#include <bits/stdc++.h>
using namespace std;
string s;
int C[101][101], n;
int solve() {
	memset(C, 0, sizeof(C));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (s[i-1] == s[j-1] && i != j)
				C[i][j] = C[i-1][j-1] + 1;
			else C[i][j] = max(C[i-1][j], C[i][j-1]);
	return C[n][n];
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		cin>>s;
		printf("%d\n", solve());
	}
}

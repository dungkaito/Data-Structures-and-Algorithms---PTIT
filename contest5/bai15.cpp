#include<bits/stdc++.h>
using namespace std;

int m,n,p;
string s1,s2,s3;
int ans[101][101][101];

int solve () {
	memset(ans, 0 ,sizeof(ans));
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=p; k++)
			if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
				ans[i][j][k] = ans[i-1][j-1][k-1] + 1;
			else
				ans[i][j][k] = max(ans[i][j-1][k], max(ans[i-1][j][k], ans[i][j][k-1]));
	return ans[m][n][p];
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>m>>n>>p;
		cin>>s1>>s2>>s3;
		printf ("%d\n", solve());
	}
}

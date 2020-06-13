#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i=0; i<=n; i++)
#define sz(a) (a.size())

string s1,s2;
int ans[1001][1001];

int solve (int m, int n) {
	memset(ans, 0 ,sizeof(ans));
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
			if (s1[i-1] == s2[j-1])
				ans[i][j] = ans[i-1][j-1] + 1;
			else
				ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
	return ans[m][n];
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>s1>>s2;
		printf ("%d\n", solve(sz(s1), sz(s2)));
	}
}

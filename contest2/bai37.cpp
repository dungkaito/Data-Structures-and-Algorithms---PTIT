#include<bits/stdc++.h>
using namespace std;

int m, n, maTranKe[21][21], marked[21], ans;

void dfs(int u, int currentStep) {
	ans = max(ans, currentStep);
//	marked[u]=1;
	for (int v=0; v<n; v++) {
		if (maTranKe[u][v]==1 /* && marked[v]==0 */) {
			maTranKe[u][v]=maTranKe[v][u]=0;
			dfs(v, currentStep+1);
			maTranKe[u][v]=maTranKe[v][u]=1;
//			marked[v]=0;
		}
	}
}

void solve() {
	ans = -1;
//	memset(marked, 0, sizeof(marked));
	for (int v = 0; v < n; v++) {
			dfs(v,0);
	}
	cout<<ans<<"\n";
}

void input() {
	int x,y;
	cin>>n>>m;
	memset(maTranKe, 0, sizeof(maTranKe));
	for(int i=0 ;i<m; i++) {
		cin>>x>>y;
		maTranKe[x][y]=maTranKe[y][x]=1;
	}
}

int main() {
	int t; cin>>t;
	while(t--) {
		input();
		solve();
	}
	return 0;
}

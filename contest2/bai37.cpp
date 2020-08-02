#include <bits/stdc++.h>
using namespace std;

int n, m, a[25][25], ans;

void dfs(int u, int step) {
	ans = max(ans, step);
	for (int v=0; v<n; v++) {
		if (a[u][v] == 1) {
			a[u][v]=a[v][u]=0;
			dfs(v,step+1);
			a[u][v]=a[v][u]=1;
		}
	}
}

int main() {
	int t, u,v ; cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (int i=0; i<m; i++) {
			cin >> u >> v;
			a[u][v] = a[v][u] = 1;
		}
		ans = 0;
		for (int i=0; i<n; i++) dfs(i, 0);
		cout << ans << endl;
	}
}

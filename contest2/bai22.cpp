#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0; i<n; i++)

int n, a[15][15] ,check;
string ans;

void Try(int x, int y) {
	int xx = x+1, yy = y+1;
	if (x == n-1 && y == n-1) {
		check = 1;
		cout << ans << " ";
	}
	if (xx>=0 && xx<n && a[xx][y]==1) {
		//D
		ans += 'D';
		Try(xx, y);
		ans.resize(ans.size()-1);
	}
	if (yy>=0 && yy<n && a[x][yy]==1) {
		//R
		ans += 'R';
		Try(x, yy);
		ans.resize(ans.size()-1);
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; ans.clear(); check = 0;
		forn(i,n) forn(j,n) cin >> a[i][j];
		if (a[0][0]==0) { cout << -1 << endl;continue;}
		ans = "";
		Try(0, 0);
		if (!check) cout <<"-1";
		cout << endl;
	}
}

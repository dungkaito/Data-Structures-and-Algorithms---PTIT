#include <bits/stdc++.h>
using namespace std;

int n, a[10][10], check;
string s;
bool visited[10][10];

void Try(int x, int y) {
	if (x == n-1 && y == n-1) {
		check = 1;
		cout << s << " ";
	}
	if (x+1>=0 && x+1<n && a[x+1][y] && !visited[x+1][y]) {
		// D
		visited[x+1][y] = 1; s += 'D';
		Try(x+1, y);
		visited[x+1][y] = 0; s.resize(s.size()-1);
	}
	if (y-1>=0 && y-1<n && a[x][y-1] && !visited[x][y-1]) {
		// L
		visited[x][y-1] = 1; s += 'L';
		Try(x, y-1);
		visited[x][y-1] = 0; s.resize(s.size()-1);
	}
	if (y+1>=0 && y+1<n && a[x][y+1] && !visited[x][y+1]) {
		// R
		visited[x][y+1] = 1; s += 'R';
		Try(x, y+1);
		visited[x][y+1] = 0; s.resize(s.size()-1);
	}
	if (x-1>=0 && x-1<n && a[x-1][y] && !visited[x-1][y]) {
		// U
		visited[x-1][y] = 1; s += 'U';
		Try(x-1, y);
		visited[x-1][y] = 0; s.resize(s.size()-1);
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) 
			for (int j=0; j<n; j++) 
				cin >> a[i][j];
		if (a[0][0] == 0) cout << -1;
		else {
			memset(visited, false, sizeof(visited));
			visited[0][0] = 1;
			s = "";
			check = 0;
			Try(0,0);
			if (check == 0) cout << -1;
		}
		cout << endl;
	}
}

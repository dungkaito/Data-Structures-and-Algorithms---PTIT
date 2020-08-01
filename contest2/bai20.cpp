#include <bits/stdc++.h>
using namespace std;

vector < vector<int> > ans;
vector <int> a;

int main() {
	int t, n; cin >> t;
	while (t--) {
		cin >> n; a.clear(); a.resize(n); ans.clear();
		for (int i=0; i<n; i++) cin >> a[i];
		while (n>0) {
			ans.push_back(a);
			for (int i=0; i<n-1; i++) a[i] += a[i+1];
			a.resize(--n);
		}
		for (int i=ans.size()-1; i>=0; i--) {
			cout << "[";
			for (int j=0; j<ans[i].size()-1; j++)
				cout << ans[i][j] << " ";
			cout << ans[i][ans[i].size()-1] << "] ";
		}
		cout << endl;
	}
}

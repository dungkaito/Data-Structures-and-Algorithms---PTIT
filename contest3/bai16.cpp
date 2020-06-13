#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d) {
	vector<int> ans;
	while (1) {
		if (d == 1) {
			ans.push_back(s); 
			break;
		}
		else if (s > 1) {
			int tmp = 9;
			while (tmp >= s) tmp--;
			ans.push_back(tmp);
			s -= tmp; d--;
		}
		else if (s == 1) {
			ans.push_back(0); 
			d--;
		}
		
	}
	if (ans[ans.size()-1] >= 10) {
		cout<<"-1\n"; 
		return;
	}
	for (int i = ans.size()-1; i>=0; i--) cout<<ans[i]; cout<<endl;
}

int main() {
	int t, S, D; cin>>t;
	while (t--) {
		cin>>S>>D;
		solve(S, D);
	}
}

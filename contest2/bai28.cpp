#include<bits/stdc++.h>
using namespace std;
int n,x,a[21],kt;
void solve(int x, vector<int> ans, int i) {
	if(x<0) return;
	if(x==0) {
		cout<<"[";
		for(int p=0; p<ans.size()-1; p++) cout<<ans[p]<<" ";
		cout<<ans[ans.size()-1]<<"] ";
		kt=1;
	}
	
	while(i<n && x>=a[i]) {
		ans.push_back(a[i]);
		solve(x-a[i],ans, i);
		ans.pop_back();
		i++;
	}
}
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n>>x;
		vector<int> ans;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n ;j++) {
				if(a[i]>a[j]) swap(a[i],a[j]);
			}
		}
		kt=0;
		solve(x,ans,0);
		if(kt==0) cout<<"-1";
		cout<<"\n";
	}
}

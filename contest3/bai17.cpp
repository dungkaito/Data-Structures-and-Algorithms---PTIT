#include<bits/stdc++.h>
using namespace std;
int k;
string s;
void solve() {
	int len = s.size();
	int freq[26]={0};
	for (int i=0; i<len; i++)
		freq[s[i]-'A']++;
	while (k>0) {
		sort(freq, freq+26, greater<int>());
		freq[0]--;
		k--;
	}
	//output
	long long ans=0;
	for (int i=0 ;i<26; i++) ans += freq[i]*freq[i];
	cout<<ans<<endl;
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>k;
		cin>>s;
		solve();
	}
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int t; cin>>t;
	while (t--) {
		cin>>s;
		int len = s.size();
		int freq[26] = {0};
		for (int i=0; i<len; i++) freq[s[i] - 'a']++;
		int max = *max_element(freq, freq+26);
		if (len%2 == 0) {
			if (max <= len/2) cout<<"1\n";
			else cout<<"-1\n";
		}
		else {
			if (max <= len/2 + 1) cout<<"1\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}

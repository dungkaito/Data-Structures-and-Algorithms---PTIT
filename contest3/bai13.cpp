#include<bits/stdc++.h>
using namespace std;

struct Freq{
	char kyTu;
	int count;
};

bool cmp (Freq a, Freq b) {
	if (a.count == b.count) return a.kyTu < b.kyTu;
	return a.count > b.count;
}

int solve (string s, int D) {
	int len=s.size();
	Freq freq[26];
	for (int i=0; i<26; i++) {
		freq[i].kyTu = i+'a';
		freq[i].count=0;
	}
	
	for (int i=0; i<len; i++){
		freq[s[i]-'a'].count++;
		s[i] = '\0'; //xoa het de ty dien vao lam ket qua.
	}
	
	sort(freq, freq+26, cmp);
	
	for (int i=0 ;i<26; i++) {
		if (freq[i].count > 0) {
			int tmp=i;
			while(s[tmp] != '\0') tmp++; //tim o trong
			// dien lan luot tung ky tu cach nhau 1 khoang D
			for (int p=0; p<freq[i].count; p++) {
				if (tmp + p*D >= len) return -1;
				s[tmp + p*D] = freq[i].kyTu;
			}
		}
	}
	return 1;
}

int main() {
	string s;
	int t, D; cin>>t;
	while(t--) {
		cin>>D;
		cin>>s;
		for (int i=0; i<s.size(); i++) {
			if (s[i]<97) s[i]+=32;
		}
		cout << solve(s, D) <<"\n";
	}
}

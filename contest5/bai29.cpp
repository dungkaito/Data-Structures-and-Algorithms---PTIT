#include<bits/stdc++.h>
using namespace std;
int tinh(string s) {
	if (s[0] == '0') return 0;
	int i, F[41] = {0}, n = s.size();
	F[0] = 1; F[1] = 1;
	for (i = 2; i <= n; i++) {
		if (s[i-1] > '0') F[i] = F[i-1];
		if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6')
			F[i] = F[i] + F[i-2];
	}
	return F[n];
}
int main() {
	int t;
	string s;
	cin>>t;
	while (t--) {
		cin>>s;
		cout<<tinh(s)<<endl;
	}
}

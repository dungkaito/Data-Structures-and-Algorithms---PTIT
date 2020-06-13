#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=1; i<=n; i++)
int tinh(string s1, string s2) {
	int C[101][101] = {0}, i, j, n=s1.size(), m=s2.size();
	forn(i,n) C[i][0] = i;
	forn(i,m) C[0][i] = i;
	forn(i,n)
		forn(j,m)
			if (s1[i-1] == s2[j-1])
				C[i][j] = C[i-1][j-1];
			else
				C[i][j] = min(C[i][j-1], min(C[i-1][j], C[i-1][j-1])) + 1;	
	return C[n][m];
}
int main() {
	string s1,s2;
	int t; cin>>t;
	
	while (t--) {
		cin>>s1>>s2;
		cout<<tinh(s1, s2)<<endl;
	}
}

/* open with vscode
abcbadd
Fij = 1 nếu từ si -> sj đối xứng

i == j     => F=1
si != sj  => Fij = 0
si == sj => Fij = Fi+1,j-1

check lần lượt theo độ dài dãy con tăng dần: k = 3->n (k=1,2 checked)
	for i = 0 - > n-k //start index of substring
		gán j = i+k-1 //end index of substring
		check dp
			nếu true thì ans=k;
return ans
*/
#include<bits/stdc++.h>
using namespace std;
bool F[1001][1001];
int solve(string s) {
	int ans = 1, k, i, j, n=s.size();

	memset(F, 0, sizeof(F));
	for (i=0; i<n; i++) F[i][i] = true;
	for(i=0; i<n-1; i++)
		if (s[i] == s[i+1]) {
			F[i][i+1] = true; 
			ans = 2;
		}
	for (k=2; k<=n; k++)
		for (i=0; i<=n-k; i++) {
			j = i + k - 1;
			if (k>2 && s[i]==s[j] && F[i+1][j-1]) {
				F[i][j] = true;
				ans = max(ans, k);
			}
		}
	return ans;
}
int main() {
	int t; cin>>t;
	string s;
	while (t--) {
		cin>>s;
		cout<<solve(s)<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll F[93];
char fiboWord(int n, long long i) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (i <= F[n-2]) return fiboWord(n-2, i);
	return fiboWord(n-1, i-F[n-2]);
}
int main() {
	int t, n; cin>>t;
	ll i;
	F[1] = 1; F[2] = 1;
	for (int i=3; i<=92; i++) F[i] = F[i-2] + F[i-1];
	while (t--) {
		cin>>n>>i;
		cout<<fiboWord(n,i)<<endl;
	}
}

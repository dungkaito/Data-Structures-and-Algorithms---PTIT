#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M = 1e9+7;

ll powM(ll n, ll r) {
	if (r==0) return 1;
	ll x = powM(n,r/2);
	if (r%2==0) return x*x%M;
	return n*(x*x%M)% M;
}

ll dao (ll n) {
	ll res=0; 
	while (n>0) {
		res = res*10 + n%10;
		n/=10;
	}
	return res;
}

int main() {
	int t; cin>>t;
	ll n, r;
	while(t--) {
		cin>>n;
		r = dao(n);
		cout<<powM(n, r)<<endl;
	}
}


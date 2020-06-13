#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M = 1e9+7;
int main() {
	ll n;
	cin>>n;
	priority_queue <ll, vector<ll>, greater<ll> > pq;
	ll input;
	for (int i=0; i<n; i++) {
		cin>>input;
		pq.push(input);
	}
	ll ans=0;
	while (pq.size()>1) {
		ll first = pq.top(); pq.pop();
		ll second = pq.top(); pq.pop();
		ans = (ans%M + first%M + second%M)%M;
		pq.push((first%M + second%M)%M);
	}
	cout<<ans<<endl;
	return 0;
}

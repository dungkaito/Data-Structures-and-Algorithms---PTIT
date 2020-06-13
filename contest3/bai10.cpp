#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; cin>>t;
	ll n;
	while(t--) {
		cin>>n;
		priority_queue < ll, vector<ll>, greater<ll> > pq;
		int input;
		for (int i=0 ; i<n; i++) {
			cin>>input;
			pq.push(input);
		}
		ll ans = 0;
		while(pq.size()>1) {
			int first = pq.top(); pq.pop();
			int second = pq.top(); pq.pop();
			ans += first + second;
			pq.push(first + second);
		}
		cout<<ans<<endl;
	}
}

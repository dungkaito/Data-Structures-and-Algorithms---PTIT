#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> a;
vector<ll> b;
int main() {
	int t; cin>>t;
	while (t--) {
		a.clear(); b.clear();
		cin>>n;
		int input;
		for (int i=0; i<n; i++) {
			cin>>input; 
			a.push_back(input);
		}
		for (int i=0; i<n; i++) {
			cin>>input; 
			b.push_back(input);
		}
		
		sort(a.begin(), a.end()); sort(b.begin(), b.end(), greater<ll>());
		
		ll ans = 0;
		for(int i=0; i<n; i++) ans = ans + a[i]*b[i];
		cout<<ans<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	long long ans, k, n, a[51];
	while(t--) {
		cin>>n>>k;
		for(int i=0; i<n; i++) cin>>a[i];
		sort (a, a+n);
		if (k>n-k) k=n-k;
		ans = 0;
		for (int i=k; i<n; i++) ans += a[i];
		for (int i=0 ;i<k; i++) ans -= a[i];
		cout<<ans<<endl;
	}
}

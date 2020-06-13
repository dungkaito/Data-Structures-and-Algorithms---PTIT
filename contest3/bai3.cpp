#include<bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
int main() {
	int t, n; cin>>t;
	long long ans;
	while(t--) {
		cin>>n;
		int a[n];
		for(int i=0; i<n ;i++) cin>>a[i];
		sort(a, a + n);
		ans=0;
		for (int i=0; i<n; i++)
			ans = (ans + (i%M * a[i]%M)%M)%M;
		cout<<ans<<endl;
	}
}

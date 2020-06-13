#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	int t, n; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>a[i];
		sort(a, a+n);
		int i = 0;
		for (int j=n/2; j<n; j++)
			if (a[i]*2 <= a[j]) i++;
		cout<<n-i<<"\n";
	}
	return 0;
}

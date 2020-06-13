#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	long long n, a[21], x, y;
	while (t--) {
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		sort (a, a+n);
		x = 0; y = 0;
		for (int i=0; i<n; i+=2) x = x*10 + a[i];
		for (int i=1; i<n; i+=2) y = y*10 + a[i];
		cout<<x+y<<endl;
	}
}

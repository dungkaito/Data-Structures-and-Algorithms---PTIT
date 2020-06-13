#include <bits/stdc++.h>
using namespace std;
long long n, a[51], aSorted[51];
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) { cin>>a[i]; aSorted[i]=a[i];}
		sort (aSorted, aSorted + n);
		int test=1;
		for (int i=0; i<n/2; i++) {
			if (a[i] < a[n-i-1]) {
				if (a[i] != aSorted[i] || a[n-i-1] != aSorted[n-i-1]){
					test = 0; 
					break;
				}
			}
			else {
				if (a[n-i-1] != aSorted[i] || a[i] != aSorted[n-i-1]){
					test = 0; 
					break;
				}
			}
		}
		if(test == 1) cout<<"Yes\n";
		else cout<<"No\n";
	}
}

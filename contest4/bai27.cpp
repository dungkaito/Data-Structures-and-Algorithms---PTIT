#include<bits/stdc++.h>
using namespace std;
typedef long long li;
li N,L,R;
li doDai(li n) {
	if (n==0 || n==1) return 1;
	return 2 * doDai(n/2) + 1;
}
li demSoBit1 (li start, li end, li n) {
	if (start>R || end<L) return 0;
	if (L<=start && end<=R) return n;
	li mid = (start + end) / 2;
	if (L<=mid && mid<=R)
		return demSoBit1(start, mid-1, n/2) + demSoBit1(mid+1, end, n/2) + n%2;
	return demSoBit1(start, mid-1, n/2) + demSoBit1(mid+1, end, n/2);  
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>N>>L>>R;
		cout<<demSoBit1(1, doDai(N), N)<<endl;
	}
	return 0;
}

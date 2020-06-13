#include <bits/stdc++.h>
using namespace std;
int a[100001];
void binarySearch (int left, int right, int value) {
	if(left > right)
		cout<<"NO\n";
	else {
		int mid = (left + right) / 2;
		if (a[mid] == value) cout << mid+1 << "\n";
		else if (value < a[mid]) binarySearch(left, mid-1, value);
		else binarySearch(mid+1, right, value);
	}
}
int main() {
	int t, n, k; cin>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=0; i<n; i++) cin>>a[i];
		binarySearch(0, n-1, k);
	}
}

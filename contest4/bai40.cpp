#include<bits/stdc++.h>
using namespace std;

int a[1001], n;

int binarySearch(int start, int end) {
	if (start > end && end == n-1) return n;
	if (start > end) return 0;
	int mid = (start + end) / 2;
	if (a[mid] == 1 && a[mid-1]==0 && mid>0) return mid;
	if (a[mid] == 0) return binarySearch(mid+1, end);
	return binarySearch(start, mid-1);
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>a[i];
		cout<<binarySearch(0, n-1)<<endl;
	}
}

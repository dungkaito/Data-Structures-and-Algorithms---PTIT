#include<bits/stdc++.h>
using namespace std;
int n, a[101];
int maxCrossArray(int low, int high, int mid) {
	int sum=0, maxLeft=INT_MIN, maxRight=INT_MIN;
	for (int i=mid; i>=low; i--) {
		sum += a[i];
		if (sum > maxLeft) maxLeft = sum;
	}
	sum=0;
	for (int i=mid+1; i<=high; i++) {
		sum += a[i];
		if (sum > maxRight) maxRight = sum;
	}
	return maxLeft + maxRight;
}
int maxSubArray(int low, int high) {
	if (low == high) return a[low];
	int mid = (low + high) / 2;
	int maxLeft = maxSubArray(low, mid);
	int maxRight = maxSubArray(mid+1, high);
	int maxCross = maxCrossArray(low, high, mid);
	int res = (maxLeft < maxRight) ? maxRight : maxLeft;
	return ( (res < maxCross) ? maxCross : res );
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++) cin>>a[i];
		cout<<maxSubArray(0, n-1)<<endl;
	}
}

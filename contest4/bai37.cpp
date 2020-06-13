#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x;
ll a[10000001];

ll binarySearch(int start, int end){
	if (start > end) return -2; 

	if (a[end] <= x) return end;

	int mid = (start + end) / 2;

	if (a[mid] == x) return mid;

	if (mid>0 && a[mid-1]<=x && a[mid]>x) return mid-1;

	if (a[mid]>x) return binarySearch(start, mid-1);
	return binarySearch(mid+1, end);
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n>>x;
		for (int i=0; i<n; i++) cin>>a[i];
		cout<<binarySearch(0, n-1) + 1<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i=0; i<int(n); i++)
typedef long long li;
int n;
li a[10000001];
li merge(int left, int right, int mid) {
	li sorted[n], inv_count=0;
	int i=left, j=mid+1, k=left;
	while (i <= mid && j<=right)
		if (a[i] <= a[j])
			sorted[k++] = a[i++];
		else {
			sorted[k++] = a[j++];
			inv_count += mid-i+1;
		}
	while (i<=mid)
		sorted[k++] = a[i++];
	while (j<=right)
		sorted[k++] = a[j++];
	for (i=left; i<=right; i++)
		a[i] = sorted[i];
	return inv_count;
}
li mergeSort(int left, int right) {
	li inv_count=0;
	if (left < right){
		int mid = (left + right) / 2;
		inv_count += mergeSort(left, mid);
		inv_count += mergeSort(mid+1, right);
		inv_count += merge(left, right, mid);
	}
	return inv_count;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while (t--) {
		cin>>n;
		forn(i,n) cin>>a[i];
		cout<<mergeSort(0, n-1)<<endl; 
	}
}

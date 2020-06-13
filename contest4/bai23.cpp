#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, size;

ll soLuongPhanTu (int n) {
	if (n==0) return 1;
	return soLuongPhanTu(n-1) * 2 + 1;
}

ll binarySearch(ll start,ll end, int n) {
	ll mid = (start + end) / 2;
	if (k == mid) return n;
	else if (k > mid) binarySearch(mid + 1, end, n-1);
	else binarySearch(start, mid-1, n-1);
}

int main() {
	int t, n; cin>>t;
	while (t--) {
		cin>>n>>k;
		if(k%2 == 1) {
			cout<<"1\n"; 
			continue;
		}
		k = k - 1;
		size = soLuongPhanTu(n-1);
		cout<<binarySearch(0, size-1, n)<<endl;
	}
	return 0;
}

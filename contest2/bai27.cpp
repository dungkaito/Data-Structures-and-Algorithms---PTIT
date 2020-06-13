#include<bits/stdc++.h>
using namespace std;
int A[21], n, k, s, daDuyet[21]={0};
bool check;
void Try (int sum, int dem) {
	if (check == true) return;
	if (dem == k) {
		check = true;
		return;
	}
	for (int i=0; i<n; i++) {
		
		if (daDuyet[i] == 0) {
			daDuyet[i] = 1;
			if (sum == s) {
				Try(0, dem+1); return;	
			}
			if (sum > s) return;
			else Try (sum + A[i], dem);
		}
		daDuyet[i] = 0;
	}
}
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n>>k;
		s=0; check = false;
		for (int i=0; i<n; i++) {
			cin>>A[i];
			s = s + A[i];
		}
		if (s % k != 0) cout<<"0\n";
		else {
			s /= k;
			Try(0, 0);
			if (check == true) cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
}

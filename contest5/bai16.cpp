#include<bits/stdc++.h>
using namespace std;
int A[1001], F[1001], n;
int tinh() {
	int kq=1;
	for (int i=1; i<=n; i++) {
		F[i]=A[i];
		for (int j=0; j<i; j++) {
			if (A[j] < A[i]) {
				F[i] = max(F[i], F[j] + A[i]);
			}
		}
		kq = max(kq, F[i]);
	}
	return kq;
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		for(int i=1; i<=n; i++) cin>>A[i];
		cout<<tinh()<<endl;	
	}
}

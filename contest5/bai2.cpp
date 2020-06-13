#include<bits/stdc++.h>
using namespace std;
int A[1001], F[1001], n;
int tinh() {
	int kq=F[0]=1;
	for (int i=1; i<n; i++) {
		F[i]=1;
		for (int j=0; j<i; j++)
			if (A[j] < A[i] && F[i] < F[j] + 1)
				F[i] = F[j] + 1;
		kq = max(kq, F[i]);
	}
	return kq;
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];
	cout<<tinh()<<endl;
}

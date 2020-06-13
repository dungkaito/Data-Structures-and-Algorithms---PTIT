#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
int A[1001], F[1001], n, k;
int tinh() {
	int i,j;
	memset(F, 0, sizeof(F));
	F[0] = 1;
	for(i = 1; i <= k; i++)
		for (j = 1; j <= n; j++)
			if (A[j]<=i)
				F[i] = (F[i] +  F[i-A[j]])%M;
	return F[k];
}
int main() {
	int t, i;
	cin>>t;
	while (t--) {
		cin>>n>>k;
		for (i=1; i<=n; i++) cin>>A[i];
		cout<<tinh()<<endl;
	}
}

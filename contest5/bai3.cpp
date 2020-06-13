#include<bits/stdc++.h>
using namespace std;
int A[201], F[40001], N, S;
int kt() {
	memset(F, 0, sizeof(F));
	F[0] = 1; int i,j;
	for (i=1; i<=N; i++)
		for (j=S; j>=A[i]; j--)
			if (F[j]==0 && F[j-A[i]]==1)
				F[j]=1;
	return F[S];
}
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>N>>S;
		for (int i=1; i<=N; i++) cin>>A[i];
		if (kt()) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

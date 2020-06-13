#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
typedef long long ll;

int n;
ll k;

struct MaTran{
	ll f[11][11];
};

MaTran operator * (MaTran A, MaTran B) {
	MaTran res;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			res.f[i][j]=0;
			for (int k=0; k<n; k++) {
				res.f[i][j] = (res.f[i][j] + A.f[i][k] * B.f[k][j] % M) % M;
			}
		}
	}
	return res;
}

MaTran powM(MaTran A, ll k) {
	if (k==1) return A;
	MaTran x = powM(A, k/2);
	if (k%2) return A*x*x;
	return x*x;
}

int main() {
	int t; cin>>t;
	MaTran A;
	while (t--) {
		cin>>n>>k;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				cin>>A.f[i][j];
		
		A = powM (A, k);
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++){
				cout<<A.f[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

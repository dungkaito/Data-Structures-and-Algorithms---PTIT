#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;

typedef long long ll;

ll n;

struct MaTran {
	ll f[2][2];
};

MaTran operator * (MaTran A, MaTran B) {
	MaTran res;
	res.f[0][0] = (A.f[0][0] * B.f[0][0]%M + A.f[0][1] * B.f[1][0]%M)%M;
	res.f[0][1] = (A.f[0][0] * B.f[0][1]%M + A.f[0][1] * B.f[1][1]%M)%M;
	res.f[1][0] = (A.f[1][0] * B.f[0][0]%M + A.f[1][1] * B.f[1][0]%M)%M;
	res.f[1][1] = (A.f[1][0] * B.f[0][1]%M + A.f[1][1] * B.f[1][1]%M)%M;
	return res;
} 

MaTran powM (MaTran A, ll n) {
	if (n==1) return A;
	MaTran x = powM(A, n/2);
	if (n%2 == 0) return x*x;
	return A*x*x;
}

int main() {
	int t; cin>>t;
	MaTran A;
	while (t--) {
		cin>>n;
		A.f[0][0] = 0; A.f[0][1] = 1; 
		A.f[1][0] = 1; A.f[1][1] = 1;
		A = powM(A, n-1);
		cout<<A.f[1][1]<<endl;
	}
}

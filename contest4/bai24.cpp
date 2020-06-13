#include<bits/stdc++.h>
using namespace std;

int M=123456789;

long long powM (int a, long long b) {
	if (b==0) return 1;
	long long x = powM(a, b/2);
	if (b%2 == 0) return (x%M * x%M) % M;
	return (a * x%M * x%M) % M;
}

int main() {
	long long n; 
	int t; cin>>t;
	while (t--) {
		cin>>n;
		//trong toan hoc da chung minh, co 2^(n-1) cach bieu dien n thanh tong cac so nho hon no
		cout<<powM(2, n-1)<<endl;
	}
}

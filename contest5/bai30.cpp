#include<bits/stdc++.h>
using namespace std;
int F[10001];
void tinh() {
	int i,j;
	F[1] = 1; F[2] = 2; F[3] = 3;
	for(i=4; i<=10000; i++) {
		F[i] = i;
		for (j=1; j<=sqrt(i); j++)
			F[i] = min(F[i], F[i-j*j] + 1);
	}
}
int main() {
	int t,n; 
	tinh();
	cin>>t;
	while (t--) {
		cin>>n;
		cout<<F[n]<<endl;
	}
	return 0;
}

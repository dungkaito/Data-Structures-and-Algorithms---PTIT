#include<bits/stdc++.h>
using namespace std;
long long C[30][30];
void tinh() {
	int i,j;
	memset(C, 0, sizeof(C));
	for(i=1; i<=25; i++) {
		C[i][0] = 1;
		C[0][i] = 1;
	}
	for (i=1; i<=25; i++)
		for (j=1; j<=25; j++)
			C[i][j] = C[i-1][j] + C[i][j-1];
}
int main() {
	int t,n,m; 
	tinh();
	cin>>t;
	while (t--) {
		cin>>n>>m;
		cout<<C[n][m]<<endl;
	}
}

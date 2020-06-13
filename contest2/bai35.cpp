#include<bits/stdc++.h>
using namespace std;

int n,k,s, X[11], dem;

void xuLy() {
	int sum=0;
	for(int i=1; i<=k; i++)
		sum = sum + X[i];
	if (sum==s) dem++;
}

void Try(int i) {
	for (int j=X[i-1]+1; j<=n-k+i; j++) {
		X[i]=j;
		if(i==k) xuLy();
		else Try(i+1);
	}
}

int main() {
	while(1) {
		cin>>n>>k>>s;
		if(n==0 && k==0 &&s==0) break;
		X[0]=0; dem=0;
		Try(1);
		cout<<dem<<endl;
	}
	return 0;
}

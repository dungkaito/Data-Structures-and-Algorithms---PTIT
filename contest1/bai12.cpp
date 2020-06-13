#include <bits/stdc++.h>

using namespace std;

bool check(int x[], int n, int k) {
	int sum=0; 
	for(int i=0; i<n; i++) sum+=x[i];
	if(sum==k)return true;
	return false;
}

void in(int x[], int n){
	for (int i=0; i<n;i++) cout<<x[i];
	cout<<endl;
}

void sinhkt(int x[], int n, int k) {
	int i;
	while(true) {
		i=n-1;
		while(i>=0 && x[i]==1) i--;
		if(i<0) {
			if (check(x,n,k)) in(x,n);
			break;
		}
		else{
			x[i]=1;
			for(int j=i+1; j<n ;j++) x[j]=0;
			//sinh xong
			if (check(x,n,k)) in(x,n);
		}
	}
}

int main() {
	int t,n,k,x[16],i;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for(i=0;i<n;i++) x[i]=0;
		if(check(x,n,k)) in(x,n);
		sinhkt(x,n,k);
	}
}


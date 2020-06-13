#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,i,j,n,x[10];cin>>t;
	while(t--) {
		cin>>n;
		for (i=0; i<n; i++) x[i]=i+1;
		
		while(true){
			for (i=0; i<n;i++) cout<<x[i];
			cout<<" ";
			
			i=n-2;
			while(i>=0 && x[i]>=x[i+1]) i--;
			//tim duoc i roi
			
			if(i<0) break;
			else {
				j=n-1;
				while(j>i && x[j]<x[i]) j--;
				swap(x[j],x[i]);
				for (int l=i+1, r=n-1; l<r; l++,r--) swap(x[l],x[r]);
			}
		}
		cout<<endl;
	}
	return 0;
}

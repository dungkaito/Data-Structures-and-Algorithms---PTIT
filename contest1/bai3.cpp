#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,x[1001],i;cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++)cin>>x[i];
		
		i=n-2;
		while(i>=0 && x[i]>=x[i+1]) i--;
		
		if(i>=0){
			int j=n-1;
			while(j>i && x[j]<x[i]) j--;
			swap(x[i],x[j]);
		
			for (int l=i+1, r=n-1; l<r; l++, r--)
				swap(x[l],x[r]);
			
			for (i=0;i<n;i++) cout<<x[i]<<" ";
			cout<<endl;
		}
		else{
			for(i=0;i<n;i++) {
				x[i]=i+1;
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

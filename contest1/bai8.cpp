#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,x[10],i;
	cin>>t;
	while(t--) {
		cin>>n;
		for ( i=0; i<n; i++) x[i]=n-i;
		
		while(true) {
			for ( i=0; i<n; i++) cout<<x[i];cout<<" ";
			
			i=n-2;
			while(i>=0 && x[i]<=x[i+1]) i--;
			
			if(i<0) break;
			else{
				for (int j=n-1; j>=i+1; j--)
					if(x[j]<x[i]){
						swap(x[j],x[i]);
						break;
					}
//				int j=n-1;
//				while(j>i && x[j]>x[i])j--;
//				swap(x[i],x[j]);						
				for(int l=i+1, r=n-1; l<r; l++,r--) swap(x[l],x[r]);
			}
		}
		cout<<endl;
	}
	return 0;
}

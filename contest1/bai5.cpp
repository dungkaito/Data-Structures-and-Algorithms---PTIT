#include <bits/stdc++.h>
using namespace std;

void in(int x[], int k) {
	for (int i=0; i<k;i++) cout<<x[i];
	cout<<" ";
}

int main() {
	int k,n,t,i,x[15];
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for (i=0; i<k; i++)	x[i]=i+1;
		
		while(true) {
			in(x,k);
			//sinh ke tiep
			i=k-1;
			while(i>=0 && x[i] == n-k+i+1) i--;
			
			if (i<0) break;
			else{
				x[i]+=1;
				for (int j=i+1; j<k; j++) x[j]=x[j-1]+1;
			}
			// 
		}
		cout<<endl;
	}
	return 0;
}

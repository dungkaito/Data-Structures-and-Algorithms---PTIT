#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k,x[1001];cin>>t;
	while(t--) {
		cin>>n>>k;
		int i=0;
		for (i=0;i<k;i++) cin>>x[i];
		
		i=k-1;
		while(i>=0 && x[i]==n-k+i+1) i--;
		
		if(i>=0) {
			x[i]+=1;
			for(int j=i+1;j<k;j++) {
				x[j]=x[j-1]+1;
			}
			for (i=0;i<k;i++) cout<<x[i]<<" ";
			cout<<endl;
		}
		else{
			for(i=0;i<k;i++){
				x[i]=i+1;
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

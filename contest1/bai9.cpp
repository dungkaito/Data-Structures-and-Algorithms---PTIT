#include<bits/stdc++.h>

using namespace std;

int main() {
	int t,n,x[10],i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			x[i]=0;
			cout<<x[i];
		}
		cout<<" ";
		
		while (true) {
			i=n-1; 
			while(i>=0 && x[i]==1) i--;
			if(i<0){
				break;
			}
			else{
				x[i]=1;
				for(int j=i+1;j<n;j++) x[j]=0;
				cout<<x[0];
				for (i=1;i<n;i++) {
					int tmp=x[i]^x[i-1];
					cout<<tmp;
				}
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}

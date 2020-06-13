#include<bits/stdc++.h>
using namespace std;

void in (int x[], int k) {
	cout<<"(";
	for(int i=0; i<k-1; i++) cout<<x[i]<<" ";
	cout<<x[k-1]<<")"<<" ";
}

int main() {
	int t,n,x[10],k,i,feed,nguyen,du; cin>>t;
	while(t--) {
		cin>>n;
		k=1; x[0]=n;
		
		while(true) {
			in(x,k);
			//sinhkt
			i=k-1;
			while (i>=0 && x[i]==1) i--;
			if(i<0) // cuoi cung: 1 1 1 1 1 1
				break;
			else{
				//sinh
				x[i]=x[i]-1;
				feed=k-(i+1)+1;
				nguyen=feed/x[i]; du=feed%x[i];
				k=i+1;
				if(nguyen>0){
					for(int j=i+1; j<=i+nguyen; j++) x[j]=x[i];
					k=k+nguyen;
				}
				if(du>0) {
					k++;
					x[k-1]=du;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
int C[15][15];
int main() {
	int n,k,x[15];
	vector<int>v;	
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>C[i][j];
	int dem=0;		
	//sinh hoan vi + cong s
	for(int i=0; i<n; i++) x[i]=i+1;
	while(1) {
		// check tinh sum
		int s=0;
		for(int i=1; i<=n; i++) {
			s+=C[i][x[i-1]];
		}
		if(s==k){
			dem++;
			for(int i=0;i<n; i++)
				v.push_back(x[i]);
		}
		//done check
		int i=n-2;
		while(i>=0 && x[i]>=x[i+1]) i--;
		if(i<0) break;
		else{
			for(int j=n-1; j>i; j--)
				if(x[j]>x[i]) {
					swap(x[i],x[j]);
					break;
				}
			for (int l=i+1, r=n-1; l<r; l++,r--) swap(x[l],x[r]);
		}
	}
	cout<<dem<<endl;
 	for(int i=0; i<v.size(); i++) {
 		if((i+1)%n==0){
 			cout<<v[i]<<endl;
		}	
		else{
			cout<<v[i]<<" ";
		}
	}
}

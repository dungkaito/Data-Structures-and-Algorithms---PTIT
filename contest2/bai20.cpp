#include<bits/stdc++.h>
using namespace std;

int n,a[11],ans[101][101];

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++)cin>>a[i];
		int hang=0;
		for(int j=0; j<n;j++) {
			ans[hang][j]=a[j];
		}
		while(n>1){
			for (int i=0; i<n; i++) {
				a[i]=a[i]+a[i+1];
			}
			n--;
			hang++;
			for(int j=0; j<n;j++)
				ans[hang][j]=a[j];
		}
		//out
		//hang=4
		n=hang+1;
		hang--;//3
		for (int i=n-1; i>=0; i--) {
			cout<<"[";
			for(int j=0; j<i-hang-1; j++) {
				cout<<ans[i][j]<<" ";
				
			}
			cout<<ans[i][i-hang-1]<<"]";
			hang-=2;
//			cout<<"]";
		}
		cout<<"\n";
	}
}

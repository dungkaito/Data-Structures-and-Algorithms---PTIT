#include<bits/stdc++.h>
using namespace std;
int n, a[11][11], kt;
string s;
void Try(int i, int j) {
	for(int k=1; k<=2; k++){
		if(i==n-1 && j==n-1) {
			kt=1;
			cout<<s<<" ";
			return;
		}
		else{
			if(k==1){ //D
				if(a[i+1][j]==1 && i+1>=0 && i+1<n) {
					s+='D';
					Try(i+1,j);
					s.resize(s.size()-1); //delete last character
				}
			}
			else{  //R
				if(a[i][j+1]==1 && j+1>=0 && j+1<n){
					s+='R';
					Try(i,j+1);
					s.resize(s.size()-1);
				}
			}
		}
	}
}
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0;j<n;j++) 
				cin>>a[i][j];
		if(a[0][0]==0) cout<<-1;
		else {
			kt=0;
			Try(0,0);
			if(kt==0) cout<<-1;
		}
		cout<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, a[9][9], kt; 
bool mark[100][100];
string s;
void Try(int i, int j) {
	for(int k=1; k<=4; k++){
		if(i==n-1 && j==n-1) {
			kt=1;
			cout<<s<<" ";
			return;
		}
		else{
			if(k==1){ //D
				if(a[i+1][j]==1 && i+1>=0 && i+1<n && !mark[i+1][j]) {
					s+='D';
					mark[i][j]=true;
					Try(i+1,j);
					s.resize(s.size()-1); //delete last character
					mark[i][j]=false;
				}
			}
			else if(k==2){  //L
				if(a[i][j-1]==1 && j-1>=0 && j-1<n && !mark[i][j-1]){
					s+='L';
					mark[i][j]=true;
					Try(i,j-1);
					s.resize(s.size()-1);
					mark[i][j]=false;
				}
			}
			else if(k==3){  //R
				if(a[i][j+1]==1 && j+1>=0 && j+1<n && !mark[i][j+1]){
					s+='R';
					mark[i][j]=true;
					Try(i,j+1);
					s.resize(s.size()-1);
					mark[i][j]=false;
				}
			}
			else if(k==4){  //U
				if(a[i-1][j]==1 && i-1>=0 && i-1<n && !mark[i-1][j]){
					s+='U';
					mark[i][j]=true;
					Try(i-1,j);
					s.resize(s.size()-1);
					mark[i][j]=false;
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
			for(int j=0;j<n;j++) {
				cin>>a[i][j];
				mark[i][j]=false;
			}
				
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

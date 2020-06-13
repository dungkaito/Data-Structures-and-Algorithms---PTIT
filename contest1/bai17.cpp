#include <bits/stdc++.h>
using namespace std;
vector<int> x;
void sinhkt(int i) {
	x[i]=9;
	for(int j=i+1; j<x.size(); j++) x[j]=0;
}

int main() {
	int t,n,i;
	
	cin>>t;
	while(t--) {
		cin>>n;
		x.clear();
		x.push_back(9);
		while(true){
			//check chia het
			long long ans=0;
//			for(i=x.size()-1; i>=0; i--)
//				ans=ans+x[i]*pow(10,x.size()-1-i);
			for(i=0;i<x.size();i++){
				ans=ans*10+x[i];
			}
				
			if(ans%n==0){
				cout<<ans<<endl;
				break;
			}
			//done check
			//sinh kt
			i=x.size()-1;
			while(x[i]==9 && i>=0) i--;
			if(i==-1){
				//insert 0 vao dau` hang
				x.insert(x.begin(),0);
				//sinh kt
				sinhkt(0);
			}
			else sinhkt(i);
			//end sinhkt
		}//end check chia het
	}//t
}

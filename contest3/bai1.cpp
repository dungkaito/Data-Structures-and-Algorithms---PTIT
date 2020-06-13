#include<bits/stdc++.h>
using namespace std;
int n, menhGia[10]={1000,500,200,100,50,20,10,5,2,1};
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans=0;
		for(int i=0; i<10; i++) {
			if(n>=menhGia[i]) {
				
				ans = ans + n/menhGia[i];
				n %= menhGia[i];
			}
			if(n==0) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}

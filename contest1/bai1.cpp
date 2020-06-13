#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	string x;
	while(t--) {
		cin>>x;
		int i=x.size()-1;
		while (i>=0 && x[i]=='1'){
			x[i]='0';
			i--;
		}
		if(i>=0) x[i]='1';
		cout<<x<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string g,b;
	scanf("%d",&t);
	while(t--) {
		cin>>g;
		b[0]=g[0];cout<<b[0];
		for(int i=1; i<g.size(); i++) {
			int tmp=g[i]^b[i-1];
			b[i]=tmp+48;
			cout<<tmp;
//			b[i]=(int)g[i]^(int)b[i-1]+48;
//			cout<<b[i];
		}
		cout<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int n, s, t[31], b[31], g=0, sum=0, FOPT=INT_MAX;

void back_track(int i) {
	for(int j=1; j>=0; j--) {
		b[i]=j;
		sum += t[i]*b[i];
		g = g + b[i]; //g la ham can duoi or  so to`
		if(i==n) {
			// update
			if(sum==s) FOPT = g;
		}
		else if(g < FOPT) back_track(i+1);
		sum-=t[i]*b[i]; g-=b[i];
	}
}

int main() {
	cin>>n>>s;
	for(int i=1; i<=n ;i++) cin>>t[i];
	back_track(1);
	if(FOPT==INT_MAX) cout<<-1<<endl;
	else cout<<FOPT<<endl;
}

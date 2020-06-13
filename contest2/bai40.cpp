#include<bits/stdc++.h>
using namespace std;

int n, mark[16]={0};
long cmin=INT_MAX, c[16][16], x[16], FOPT=INT_MAX, chiPhi=0;

void update() {
	if (chiPhi + c[x[n]][x[1]] < FOPT)
		FOPT = chiPhi + c[x[n]][x[1]];
}

void back_track(int i) {
	for (int j=2; j<=n; j++) {
		if (mark[j]==0) {
			x[i]=j;
			mark[j]=1;
			chiPhi = chiPhi + c[x[i-1]][x[i]];
			
			if(i==n) update();
			else if(chiPhi + (n-i+1)*cmin < FOPT) back_track(i+1);
			
			mark[j]=0; 
			chiPhi = chiPhi - c[x[i-1]][x[i]];
		}
	}
}

int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>c[i][j];
			if (c[i][j]<cmin && c[i][j]>0)
				cmin=c[i][j];
		}
	}
	x[1]=1;
	back_track(2);
	cout<<FOPT;
	return 0;
}

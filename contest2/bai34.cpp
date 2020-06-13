#include<bits/stdc++.h>
using namespace std;
int A[9][9], dcXuoi[18]={0}, dcNguoc[18]={0}, markCol[9]={0}, ans=-1, queen[9];

void xuLy() {
	int sum=0;
	for (int i=1; i<=8; i++) {
		sum = sum + A[i][queen[i]];
	}
	ans = max(ans, sum);
}

void Try(int i) {
	for (int j=1; j<=8; j++) {
		if (!dcXuoi[i-j+8] && !dcNguoc[i+j-1] && !markCol[j]) {
			queen[i]=j;
			dcXuoi[i-j+8]=1; dcNguoc[i+j-1]=1; markCol[j]=1;
			
			if(i==8) xuLy();
			else Try(i+1);
			
			dcXuoi[i-j+8]=0; dcNguoc[i+j-1]=0; markCol[j]=0;
		}
	}
}

int main() {
	int t; cin>>t;
	while (t--) {
		for(int i=1; i<=8; i++)
			for(int j=1; j<=8; j++) cin>>A[i][j];
		ans=-1;
		Try(1);
		cout<<ans<<endl;
	}
	return 0;
}

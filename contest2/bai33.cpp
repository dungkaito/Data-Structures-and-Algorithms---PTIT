#include<bits/stdc++.h>
using namespace std;
int n, duongCheoXuoi[21]={0}, duongCheoNguoc[21]={0}, markCol[11]={0}, dem;

void Try(int row) {
	for (int col=1; col<=n; col++) {
		if (!markCol[col] && !duongCheoXuoi[row-col+n] && !duongCheoNguoc[row+col-1]) {
			markCol[col]=1;
			duongCheoXuoi[row-col+n]=1;
			duongCheoNguoc[row+col-1]=1;
			
			if (row==n)	dem+=1;
			else Try(row+1);
			
			markCol[col]=0;
			duongCheoXuoi[row-col+n]=0;
			duongCheoNguoc[row+col-1]=0;
		}
	}
}

int main() {
	cin>>n; 
	dem=0;
	Try(1);
	cout<<dem<<endl;
	return 0;
}

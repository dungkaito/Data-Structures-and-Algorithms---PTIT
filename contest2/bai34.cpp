#include <bits/stdc++.h>
using namespace std;

int a[9][9], markCol[11], dcXuoi[21], dcNguoc[21], sum, ans;

void Try(int row) {
	if (row>8) return;
	for (int col=1; col<=8; col++) {
		if (!markCol[col] && !dcXuoi[row-col+8] && !dcNguoc[row+col-1]) {
			markCol[col] = 1; 
			dcXuoi[row-col+8] = 1;
			dcNguoc[row+col-1] = 1;
			sum += a[row][col];
			
			if (row == 8) ans = max(ans, sum);
			else Try(row+1);
			
			markCol[col] = 0;
			dcXuoi[row-col+8] = 0;
			dcNguoc[row+col-1] = 0;
			sum -= a[row][col];
		}
	}
} 

int main() {
	int t; cin >> t;
	while (t--) {
		for (int i=1; i<=8; i++)
			for (int j=1; j<=8; j++)
				cin >> a[i][j];
				
		memset(markCol, 0, sizeof(markCol));
		memset(dcXuoi, 0, sizeof(dcXuoi));
		memset(dcNguoc, 0, sizeof(dcNguoc));
		sum=0; ans=INT_MIN;
		Try(1);
		
		cout << ans << endl;
	}	
}

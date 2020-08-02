#include <bits/stdc++.h>
using namespace std;

int n, k, s, x[25], sum, cnt;

void Try(int i) {
	for (int j=x[i-1]+1; j<=n-k+i; j++) {
		x[i]=j;
		sum+=j;
		if (i==k) {
			if (sum==s) cnt++;
		}
		else Try(i+1);
		sum-=j;
	}
}

int main() {
	while (true) {
		cin >> n >> k >> s;
		if (n==0&&k==0&&s==0) break;
		cnt=0; sum=0;
		Try(1);
		cout << cnt << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

int n, k, a[15], chosen[15], sum, check;

void Try(int i) {
	if (i>=n) return;
	for (int j=1; j>=0; --j) {
		chosen[i] = j;
		sum += j*a[i];
		if (sum == k) {
			check = 1;
			//OUT
			cout << "[";
			for (int k=0; k<i; k++)
				if (chosen[k]) cout << a[k] << " ";
			cout << a[i] << "] ";
		}
		else Try(i+1);
		sum -= j*a[i];
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a, a+n);
		sum=0;
		check = 0;
		Try(0);	
		if (check == 0) cout << -1;
		cout << endl;
	}
}

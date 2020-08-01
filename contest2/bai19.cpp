#include <bits/stdc++.h>
using namespace std;

void rec(int a[], int n) {
	if (n==0) return;
	//OUT
	cout << "[";
	for(int i=0; i<n-1; i++) cout << a[i] << " ";
	cout << a[n-1] << "]\n";
	//next recur
	for (int i=0; i<n-1; i++) a[i] = a[i] + a[i+1];
	rec(a, n-1);
}

int main() {
	int t, n, a[15]; cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		rec(a, n);
	}
}

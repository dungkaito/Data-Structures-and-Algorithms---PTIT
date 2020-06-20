#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
	if (n == 1)
		return 1;
	return (josephus(n - 1, k) + k-1) % n + 1;
}

int main() {
	int t = 0;

	cin >> t;
	while (t--) {
		int n = 0, k = 0;
		cin >> n >> k;
		k++;
		cout << josephus(n, k) << endl;
	}

	return 0;
}
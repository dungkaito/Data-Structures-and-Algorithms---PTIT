#include<bits/stdc++.h>
using namespace std;
long long n, a, b;
int main() {
	int t; cin>>t;
	while (t--) {
		cin>>n;
		int check = 0;
		// a la so lan xh cua 4, b la so lan xh cua 7
		for (a = 0; a <= n/4; a++) {
			if ((n-4*a)%7 == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) cout<<"-1";
		else {
			b = (n-4*a)/7;
			for (int i=0; i<a; i++) cout<<"4";
			for (int i=0; i<b; i++) cout<<"7";
		}
		cout<<"\n";
	}
	return 0;
}

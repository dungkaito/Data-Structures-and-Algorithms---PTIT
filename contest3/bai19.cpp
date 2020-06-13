#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	long long tu, mau;
	while (t--) {
		cin>>tu>>mau;
		while (1) {
			if (mau%tu == 0) {
				cout<<"1/"<<mau/tu<<endl;
				break;
			}
			else {
				long long res = mau/tu + 1;
				cout<<"1/"<<res<<" + ";
				tu = tu*res - mau; mau = mau*res;
			}
		}
	}
	return 0;
}

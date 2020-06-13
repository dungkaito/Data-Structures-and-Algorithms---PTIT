#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> soLapPhuong;
ll solve(string num){
	ll len=num.size();
	for (int i=1000000; i>=1; i--) {
		ll tmp = soLapPhuong[i];
		int lastDigit = tmp % 10; 
		for (int j=len-1; j>=0; j--) {
			if (num[j] - '0' == lastDigit) {
				tmp /= 10;
				lastDigit = tmp % 10;
			}
		}
		if (tmp == 0) return soLapPhuong[i];
	}
	return -1;
}
int main() {
	for (ll i=0; i<=1000000; i++) soLapPhuong.push_back(i*i*i);
	
	string num;
	int t; cin>>t;
	while (t--) {
		cin>>num;
		cout<<solve(num)<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
	long long a,b,amin=0,bmin=0,amax=0,bmax=0;
	cin>>a>>b;
	int i=0;
	while(a>0) {
		int lastDigit = a%10;
		if(lastDigit==5 || lastDigit==6) {
			amin = amin + 5*pow(10,i);
			amax = amax + 6*pow(10,i);
		}
		else {
			amin = amin + lastDigit*pow(10,i);
			amax = amax + lastDigit*pow(10,i);
		}
		a/=10;
		i++;
	}
	i=0;
	while(b>0) {
		int lastDigit = b%10;
		if(lastDigit==5 || lastDigit==6) {
			bmin = bmin + 5*pow(10,i);
			bmax = bmax + 6*pow(10,i);
		}
		else {
			bmin = bmin + lastDigit*pow(10,i);
			bmax = bmax + lastDigit*pow(10,i);
		}
		b/=10;
		i++;
	}
	cout<<amin+bmin<<" "<<amax+bmax;
}

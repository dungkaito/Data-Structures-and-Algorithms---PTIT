#include<bits/stdc++.h>
using namespace std;
typedef long long li;
li binToDec (string s) {
	li res=0;
	for (int i=0; i<s.size(); i++)
		if (s[i]=='1')
			res += (s[i]-'0')*pow(2,s.size()-i-1);
	return res;
}
int main() {
	int t; cin>>t;
	string s1,s2;
	while (t--) {
		cin>>s1>>s2;
		li num1 = binToDec(s1);
		li num2 = binToDec(s2);
		cout<<num1*num2<<endl;
	}
}

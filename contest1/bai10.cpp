#include<bits/stdc++.h>

using namespace std;

int main() {
	int t,n,i;
	string s;
	cin>>t;
	while(t--) {
		cin>>s;
		cout<<s[0];
		for (int i=1;i<s.size(); i++){
			int tmp=s[i]^s[i-1];
			cout<<tmp;
		}
		cout<<"\n";
	}
}

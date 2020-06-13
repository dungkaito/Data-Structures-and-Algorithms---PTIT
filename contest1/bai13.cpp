#include<bits/stdc++.h>
using namespace std;

bool check(string s, int n, int k){
	int count=0,dem=0;
	for (int i=0; i<n; i++) {
		if(s[i]=='A') dem++;
		else dem=0;
		if(dem==k) count++;
		if(dem>k) return false;
	}
	if (count==1) return true;
	return false;
}

int main() {
	vector<string> ans;
	int n,k,i;
	string s="";
	cin>>n>>k;
	
	for (i=0; i<n; i++) {
		s+='A';
	}
	if (check(s,n,k)) ans.push_back(s);
	//sinhkt
	while (true) {
		i=n-1;
		while(i>=0 && s[i]=='B') i--;
		if(i<0)	break;
		else {
			s[i]='B';
			for(int j=i+1; j<n; j++) s[j]='A';
			if(check(s,n,k)) ans.push_back(s);
		}
	}
	//output
	cout<<ans.size()<<endl;
	for(i=0; i<ans.size(); i++) cout<<ans[i]<<endl;
	return 0;
}

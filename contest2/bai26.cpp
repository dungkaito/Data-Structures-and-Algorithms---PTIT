#include<bits/stdc++.h>
using namespace std;
string s;
void rec(int k, string &max){
	if(k==0) return;
	for(int i=0; i<s.size()-1; i++) {
		for(int j=i+1; j<s.size(); j++) {
			if(s[i]<s[j]){
				swap(s[i], s[j]);
				if(s.compare(max)>0) max=s;
				rec(k-1, max);
				swap(s[i], s[j]);
			}
		}
	}
}
int main() {
	int t=0,k=0; 
	cin>>t;
	while(t--) {
		cin>>k>>s;
		string max=s;
		rec(k,max);
		cout<<max<<endl;
	}
	
}

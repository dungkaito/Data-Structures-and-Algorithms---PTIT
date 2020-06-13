#include<bits/stdc++.h>

using namespace std;

int main() {
	int t,stt;
	string s;
	cin>>t;
	while(t--) {
		cin>>stt>>s;
		int len=s.size();
		cout<<stt<<" ";
		
		int i=len-2;
		while(i>=0 && s[i]>=s[i+1])i--;
		if(i<0){
			cout<<"BIGGEST"<<endl;
			continue;
		}
		else{
			for (int j=len-1; j>=i+1; j--)
				if(s[j]>s[i]){
					swap(s[j],s[i]);
					break;
				}
			for(int l=i+1, r=len-1; l<r; l++,r--) swap(s[l],s[r]);
			cout<<s<<endl;
		}
	}
}

//#include<bits/stdc++.h>
//using namespace std;
//
//bool danhDau[101];
//string s;
//
//void Try(int i){
//	int len=s.size();
//	for(int j=1; j<=len; j++){
//		if(danhDau[j]==true){
//			s[i]=j+64;
//			danhDau[j]=false;
//			if(i==len)
//				cout<<s<<"";
//			else 
//				Try(i+1);
//			danhDau[j]=true;
//		}
//	}
//}
//
//void solve() {
//	memset(danhDau, true, sizeof(danhDau));
//	Try(1);
//}
//
//int main() {
//	int t; cin>>t;
//	while(t--) {
//		cin>>s;
//		solve();
//		cout<<"\n";
//	}
//}
#include <bits/stdc++.h>

using namespace std;
string s;
int main() {
	int t,i; cin>>t;
	while(t--) {
		cin>>s; 
		sort(s.begin(), s.end());
//		cout<<s<<" ";
		while(1) {
			cout<<s<<" ";
			i=s.size()-2;
			while(i>=0 && s[i]>=s[i+1]) i--;
			if(i<0) break;
			else{
				for(int j=s.size()-1; j>i; j--) {
					if(s[j]>s[i]){
						swap(s[j],s[i]);
						break;
					}
				}
				for(int l=i+1, r=s.size()-1; l<r; l++, r--) {
					swap(s[l],s[r]);
				}
			}
		}
		cout<<"\n";
	}
}

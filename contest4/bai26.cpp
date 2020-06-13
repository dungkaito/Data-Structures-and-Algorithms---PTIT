#include<bits/stdc++.h>
using namespace std;
typedef long long li;
#define forn(i,n) for(int i=0; i<li(n); i++)
string a,b;
li powM(int a, li b) {
	if (b==0) return 1;
	li x=powM(a,b/2);
	if (b%2 == 0) return x*x;
	return a*x*x;
}
int main() {
	int k; cin>>k;
	if (k==10) {
		int x,y; cin>>x>>y;
		cout<<x+y;
	}
	else {
		cin>>a>>b; 
		li sizeA = a.size(), sizeB = b.size();
		//base k to dec
		int aDec=0, bDec=0;
		forn(i,sizeA) aDec += (a[i]-'0')*powM(k, sizeA-i-1);
		forn(i,sizeB) bDec += (b[i]-'0')*powM(k, sizeB-i-1);
		//sum in dec
		int sum = aDec + bDec;
		//sum dec to base k
		vector<int> ans;
		while (sum>0) {
			ans.push_back(sum%k);
			sum/=k;
		}
		//output in base k
		for (int i=ans.size()-1; i>=0; i--) cout<<ans[i];
	}
}

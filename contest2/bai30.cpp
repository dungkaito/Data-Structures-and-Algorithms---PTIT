#include<bits/stdc++.h>
using namespace std;

int n, p, s, subset[11], dem;
vector<int> ans;
vector<int> snt;

void sntNhoHonS() {
	vector<bool> mark(s+1, true);
	for(int i=2; i*i<=s; i++) {
		if(mark[i] == true) {
			for(int j=i*i; j<=s; j+=i) mark[j]=false;
		}
	}
	for(int i=2; i<=s; i++) {
		if(mark[i]) {
			if (i>=p) snt.push_back(i);
		}
	}
}

void process(){
	int sum=0;
	for(int i=0; i<n; i++) {
		sum+=subset[i];
	}
	if(sum==s) {
		dem++;
		for(int i=0; i<n; i++) {
			ans.push_back(subset[i]);
		}	
	}
}

void Try(int i) {
	int lastIndex;
	if(i != 0){
		// tim index subset[i-1] trong snt
		vector<int>::iterator it = find(snt.begin(), snt.end(), subset[i-1]);
		lastIndex = it-snt.begin();
	}
	else lastIndex=-1; //debug line 64
	// tmp la bien chay vong lap
	int tmp=lastIndex + 1;
	// max cua index vong lap
	int maxPos=snt.size()-n+i; //giong sinh to hop
	
	for(int j=snt[tmp]; tmp<=maxPos; j=snt[++tmp]){
		subset[i]=j;

		if(i==n-1) {
			process();
		}
		else Try(i+1);
	} 
}

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n>>p>>s;
		snt.clear(); ans.clear();
		sntNhoHonS(); //tim so nguyen to nho hon s lon hon p
//		snt[-1]=snt[0]; chi can tim duoc cai nay la xong
		dem=0;
//		subset[0]=7;
		Try(0);
		//output
		cout<<dem<<endl;
		for(int i=0; i<ans.size(); i=i+n) {
			for(int j=i; j<i+n; j++) {
				cout<<ans[j]<<" ";
			}	
			cout<<"\n";
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

int n,stop;
char s[10];

void in(){
	for (int i=0;i<n;i++) cout<<s[i];
	cout<<" ";
}

void sinhkt() {
	int i=n-1;
	while(i>=0 && s[i]=='B') i--;
	if(i==-1) stop=1;
	else{
		s[i]='B';
		for (int j=i+1;j<n;j++) {
			s[j]='A';
		}
	}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		stop=0;
		cin>>n;
		for(int i=0;i<n;i++) s[i]='A';
		while(!stop){
			in();
			sinhkt();
		}
		cout<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,a[11];

void result() {
	cout<<"[";
	for(int i=0; i<n-1; i++) cout<<a[i]<<" ";
	cout<<a[n-1]<<"]\n";
}

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++)cin>>a[i];
		result();
		while(n>1){
			for (int i=0; i<n; i++) {
				a[i]=a[i]+a[i+1];
			}
			n--;
			result();
		}
	}
}

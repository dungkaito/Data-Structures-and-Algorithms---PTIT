#include<bits/stdc++.h>

using namespace std;

int compare(int a[], int b[], int n){
	int tieptuc=0;
	for (int i=0; i<n; i++) {
		for(int j=0 ; j<n; j++) {
			if(a[i]==b[j]){
				tieptuc++;
				break;
			}
		}
	}
	return n-tieptuc;
}

int main() {
	int t,k,n,nhomMoi[40],nhomCu[40],i; cin>>t;
	while(t--) {
		cin>>n>>k;
		for (i=0; i<k; i++) {
			cin>>nhomMoi[i];
			nhomCu[i]=nhomMoi[i];
		}
		//sinhkt
		i=k-1;
		while(i>=0 && nhomMoi[i]==n-k+i+1) i--;
		if (i<0) {
			cout<<k<<endl;
		}
		else {
			nhomMoi[i]+=1;
			for(int j=i+1;j<k;j++) nhomMoi[j]=nhomMoi[j-1]+1;
			//so sanh
			cout<<compare(nhomCu,nhomMoi,k)<<endl;
		}
	}
}

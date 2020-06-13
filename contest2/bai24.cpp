//#include<bits/stdc++.h>
//using namespace std;
//int n, a[11],k, res[11],sum;
//void Try(int i) {
//	int tmp=i;
//	for(int j=a[tmp]; j<a[n-1]; tmp++) {
//		res[i]=j;
//		for(int l=0; l<=i ;l++) sum+=res[l];
//		if(j==25 || sum==k) {
//			if(sum==k) {
//				cout<<"[";
//				for(int l=0; l<i; l++) cout<<res[l]<<" ";
//				cout<<res[i]<<"] ";
//			}
//			sum-=j;
//		}
//		else Try(i+1);
//	}
//}
//int main() {
//	int t;
//	cin>>t;
//	while(t--) {
//		cin>>n>>k;
//		for(int i=0; i<n;i++) cin>>a[i];
//		for(int i=0; i<n-1;i++)
//			for(int j=i+1; j<n; j++)
//				if(a[i]>a[j]) swap(a[i],a[j]);
//		sum=0;
//		Try(0);
//	}
//}
#include <bits/stdc++.h>
using namespace std;
int n,k,a[11],sum,weight,res[11],check;
void Try(int i) {
	for(int j=1; j>=0; j--) {
		res[i]=j; weight-=a[i];
		if(j==1) {
			sum+=a[i];
		}
		if(sum==k || weight==0) {
			if(sum==k) {
				check=1;
				cout<<"[";
				for(int p=0; p<i; p++) {
					if(res[p]==1) cout<<a[p]<<" ";
				}
				if(res[i]==1) cout<<a[i];
				cout<<"] ";
			}
			if(j==1) sum-=a[i]; weight+=a[i];
			
		}
		else{
			Try(i+1);
			if(j==1) sum-=a[i]; weight+=a[i];
		}
	}
}
int main() {
	int t;cin>>t;
	while(t--) {
		cin>>n>>k;
		weight=0;sum=0,check=0;
		for(int i=0; i<n;i++) {
			cin>>a[i];
			weight+=a[i];
		}
		for(int i=0; i<n-1;i++)
			for(int j=i+1; j<n; j++)
				if(a[i]>a[j]) swap(a[i],a[j]);
		Try(0);
		if(check==0) cout<<-1;
		cout<<endl;
	}
}



























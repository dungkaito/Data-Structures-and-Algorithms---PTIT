//#include<bits/stdc++.h>
//using namespace std;
//int n,a[101],res[101],remain,current,check;
//void Try(int i) {
//	for(int j=1; j>=0; j--) {
//		if(check==1) break;
//		res[i]=j; 
//		if(j==1) {remain-=a[i]; current+=a[i];}
//		if(current==remain || remain==0 || current>remain || i==n){
//			if(current==remain) {
//				check=1;
//			}
//			if(j==1) {remain+=a[i]; current-=a[i];}
//		}
//		else {
//			Try(i+1);
//			if(j==1) {remain+=a[i]; current-=a[i];}
//		}
//	}
//}
//int main() {
//	int t; cin>>t;
//	while(t--) {
//		cin>>n;
//		remain=0; current=0;
//		for(int i=0; i<n;i++) {
//			cin>>a[i];
//			remain+=a[i];
//		}
//		check=0;
//		Try(0);
//		if(check==0) cout<<"NO"<<endl;
//		else cout<<"YES"<<endl;
//	}
//}

/*

#include<bits/stdc++.h>
using namespace std;
int n,a[101],sum;
bool backTrack(int sum, int i) { //actually not backtracking
	if(i==n || sum<a[i]) return false;
	if(sum==a[i]) return true;
	return backTrack(sum,i+1) || backTrack(sum-a[i],i+1);
}
bool solve(){
	if (sum%2) return false;
	sum /= 2;
	return backTrack(sum, 0);
}
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		sum=0;
		for(int i=0; i<n;i++) {
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=0; i<n-1;i++)
			for(int j=i+1; j<n; j++)
				if(a[i]>a[j]) swap(a[i],a[j]);
		if(solve()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
*/

#include <bits/stdc++.h>
using namespace std;
int n, A[101];

bool dayConCoTongBangSum(int sum) {
	bool subset[n+1][sum+1];
	
	for(int i=0; i<=n; i++)
		subset[i][0]=true;
	for(int i=1; i<=sum; i++)
		subset[0][i]=false;
	
	for(int i=1; i<=n ;i++) {
		for(int j=1; j<=sum; j++) {
			if(j < A[i-1]) {
				subset[i][j] = subset[i-1][j];
			}
			if(j >= A[i-1]) {
				subset[i][j] = subset[i-1][j] || subset[i-1][j-A[i-1]]; 
			}
		}
	}
	
	return subset[n][sum];
}

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n; 
		int sum=0;
		for(int i=0; i<n; i++) {
			cin>>A[i];
			sum+=A[i];
		}
		if(sum%2) cout<<"NO"<<endl;
		else {
			sum = sum / 2;
			if(dayConCoTongBangSum(sum)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}

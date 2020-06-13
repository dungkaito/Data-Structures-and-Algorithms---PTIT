//#include<bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//ll n,S[1001],F[1001];
//
//int partition(ll start, ll end) {
//	int pivot = F[end];
//	int pIndex = start;
//	for (ll i=start; i<end; i++) {
//		if (F[i]<=pivot) {
//			swap(F[i], F[pIndex]); swap(S[i], S[pIndex]);
//			pIndex++;
//		}
//	}
//	swap(F[pIndex], F[pivot]); swap(S[pIndex], S[pivot]);
//	return pIndex;
//}
//
//void quickSort(ll start, ll end) {
//	if (start<=end) return;
//	int pIndex = partition(start, end);
//	quickSort(start, pIndex-1);
//	quickSort(pIndex+1, end);
//}
//
//int main() {
//	int t; cin>>t;
//	while(t--) {
//		cin>>n;
//		for (int i=0; i<n; i++)	cin>>S[i];
//		for (int i=0; i<n; i++)	cin>>F[i];
//		
//		quickSort(0,n-1);
//		
//		int i=0, dem=1;
//		for(int j=1; j<n; j++) {
//			if(S[j]>=F[i]) {
//				dem++;
//				i=j;
//			}
//		}
//		cout<<dem<<endl;
//	}
//}
#include<bits/stdc++.h>
using namespace std;
struct congViec {
	int startTime, finishTime;
};

congViec cv[1001];

bool cmp (congViec a, congViec b){ 
	return a.finishTime<b.finishTime;
}

int main() {
	int t, n; cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) cin>>cv[i].startTime;
		for(int i=0; i<n; i++) cin>>cv[i].finishTime;
		sort (cv, cv+n, cmp);
		int i=0; 
		int dem=1;
		for (int j=1; j<n; j++) {
			if (cv[j].startTime >= cv[i].finishTime) {
				dem++;
				i=j;
			}
		}
		cout<<dem<<endl;
	}
	return 0;
}

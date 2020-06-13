#include<bits/stdc++.h>
using namespace std;
struct CongViec{
	int jobID, deadline, profit;
};

CongViec cv[1001];

bool cmp(CongViec a, CongViec b) {
	return a.profit>b.profit;
}

int main() {
	int t, n; cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<n; i++)
			cin>>cv[i].jobID>>cv[i].deadline>>cv[i].profit;
		sort(cv, cv+n, cmp);
	
		int daXetNgay[1001] = {0};
		int kq=0, dem=0;
		
		for (int i=0; i<n; i++) {
			while (daXetNgay[cv[i].deadline] && cv[i].deadline>0) cv[i].deadline--; //tim ngay dau tien tinh tu deadline->ngay1 ma chua dc lam`
			if (cv[i].deadline > 0) {
				daXetNgay[cv[i].deadline] = 1;
				kq += cv[i].profit; dem++;
			}
		}
		
		cout<<dem<<" "<<kq<<endl;
	}
	return 0;
}

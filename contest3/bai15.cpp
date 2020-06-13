#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, N, S, M; cin>>t;
	while(t--) {
		cin>>N>>S>>M;
		if (S*M > (S-S/7)*N) cout<<"-1\n";
		else {
			if ((S*M)%N == 0) cout<<(S*M)/N<<endl;
			else cout<<(S*M)/N+1<<endl;
		}
	}
	return 0;
}

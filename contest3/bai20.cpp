#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	string s;
	while (t--) {
		cin>>s;
		int len=s.size(), dem=0, mo=0, dong=0;
		for (int i=0; i<len; i++) {
			if (s[i]=='[') mo++;
			else dong++;
			if (dong>mo) {
				for (int j=i+1; j<len; j++) {
					if (s[j] != s[i]) {
						swap(s[i],s[j]);
						mo++; dong--;
						dem += j - i;
						break;
					}
				}
			}
		}
		cout<<dem<<endl;
	}
	return 0;
}

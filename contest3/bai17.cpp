#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int t, k; cin>>t;
	while(t--) {
		cin >> k >> s;
		
		int freq[26] = {0};
		for (int i=0; i<s.size(); i++) 
			freq[s[i]-'A']++;
			
		priority_queue <int> pq;
		for (int i=0; i<26; i++)
			if (freq[i])
				pq.push(freq[i]);
		
		while (k--) {
			int tmp = pq.top(); pq.pop();
			pq.push(--tmp);
		}
		
		long long ans = 0;
		while (!pq.empty()) {
			ans += pq.top()*pq.top();
			pq.pop();
		}
		cout << ans << endl;
	}
}
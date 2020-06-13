#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int64 solve(string s, int k) {
    if (k >= s.length()) return 0;

    int freq[26] = {0};
    for (int i=0; i<s.length(); i++)
        freq[s[i] - 'A']++;

    priority_queue <int> pq;
    for (int i=0; i<26; i++) 
        pq.push(freq[i]);
    
    while (k--) {
        int top = pq.top(); pq.pop();
        top--; pq.push(top);
    }

    int64 ans = 0;
    while (!pq.empty()) {
        int64 tmp = pq.top();
        ans += (tmp * tmp);
        pq.pop();
    }

    return ans;
}
int main() {
    int t, k; cin >> t;
    string s;
    while (t--) {
        cin >> k >> s;
        cout << solve(s, k) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> visit;
unordered_set <string> S;

int solve(int n, string s, string t) {
    queue <string> q;
    q.push(s);

    visit[s] = 1;

    string s1, s2;
    while (!q.empty()) {
        s1 = q.front(); q.pop();

        if (s1 == t) return visit[s1];

        for (int i=0; i<s1.size(); i++) {
            for (char ch='A'; ch<='Z'; ch++) {
                s2 = s1; 
                s2[i] = ch;
                if (S.find(s2) != S.end() && visit[s2] == 0) {
                    q.push(s2);
                    visit[s2] = visit[s1] + 1;
                }
            }
        }
    }
}

int main() {
    int T, n; cin >> T;
    string s, t, input;
    while (T--) {
        cin >> n >> s >> t;
        visit.clear(); S.clear();
        for (int i=0; i<n; i++) {
            cin >> input;
            S.insert(input);
            visit[input] = 0;
        }
        cout << solve(n, s, t) << endl;
    }
}
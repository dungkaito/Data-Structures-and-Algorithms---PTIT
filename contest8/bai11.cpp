#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

int base[4] = {1000, 100, 10, 1};
vector <bool> prime(10000, true);

void sieve() {
    // sang snt tu 0->9999
    for (int i=2; i*i<=9999; i++)
        if (prime[i])
            for (int j=i*i; j<=9999; j+=i)
                prime[j] = false;
}

int solve(int n, int target) {
    if (n == target) return 0;
    queue < pii > q;
    q.push(mp(n, 0));

    set <int> visit;
    visit.insert(n);

    int i, j, tmp;
    pii curNum;
    while (!q.empty()) {
        curNum = q.front(); q.pop();
        for (i=0; i<=3; i++) {
            for (j=0; j<=9; j++) {
                // thay chu so thu i trong curNum bang j
                tmp = (curNum.fi / (base[i] * 10) * 10 + j) * base[i] + curNum.fi % base[i];

                if (tmp > 1000 && prime[tmp] && visit.find(tmp) == visit.end()) {
                    if (tmp == target) return curNum.se + 1;
                    q.push(mp(tmp, curNum.se + 1));
                    visit.insert(tmp);
                }
            } // end of for j
        } // end of for i
    } // end of while
}

int main() {
    sieve();
    int t, S, T; cin >> t;
    while (t--) {
        cin >> S >> T;
        cout << solve(S, T) << endl;
    }
}
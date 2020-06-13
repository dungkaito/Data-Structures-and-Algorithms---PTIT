#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

int a[1001][1001];

int solve(int m, int n) {
    int i, j;

    queue < pair<pii, int> > q;
    q.push(mp(mp(1, 1), 0));

    bool visit[1001][1001] = {0};

    while(!q.empty()) {
        pair<pii, int> x = q.front(); q.pop();

        i =  x.fi.fi; j = x.fi.se;

        if (visit[i][j]) continue;
        visit[i][j] = 1;

        if (i == m && j == n) return x.se;
         
        if (j + a[i][j] <= n)
            q.push(mp(mp(i, j + a[i][j]), x.se + 1));

        if (i + a[i][j] <= m)
            q.push(mp(mp(i + a[i][j], j), x.se + 1));
    }
    return -1;
}

int main() {
    int t, m , n; cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                cin >> a[i][j];
        cout << solve(m, n) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define ppi pair<pair<int,int>, int>
#define mp make_pair
#define fi first
#define se second

int r, c, ans = -1;
int a[501][501];
queue <ppi> q;

bool check() {
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            if (a[i][j] == 1)
                return false;
    return true;
}

int solve() {
    while (!q.empty()) {
        ans = max(ans, q.back().se);

        ppi x = q.front(); q.pop();

        int i = x.fi.fi, j = x.fi.se;
        
        //phia tren ij
        if (i-1 >= 0 && a[i-1][j] == 1) {
            a[i-1][j] = 2;
            q.push(mp(mp(i-1, j), x.se + 1));
        }
        //phia duoi ij
        if (i+1 < r && a[i+1][j] == 1) {
            a[i+1][j] = 2;
            q.push(mp(mp(i+1, j), x.se + 1));
        } 
        //ben trai ij
        if (j-1 >=0 && a[i][j-1] == 1) {
            a[i][j-1] = 2;
            q.push(mp(mp(i, j-1), x.se + 1));
        }
        //ben phai ij
        if (j+1 < c && a[i][j+1] == 1) {
            a[i][j+1] = 2;
            q.push(mp(mp(i, j+1), x.se + 1));
        }
    }
    if (!check()) return -1;
    return ans;
}

int main() {
    //initialize
    cin >> r >> c;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2)
                q.push(mp(mp(i, j), 0));
        }
    cout << solve() << endl;
    return 0;
}
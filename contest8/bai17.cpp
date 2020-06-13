#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define ppi pair<pair<int,int>, int>
#define mp make_pair
#define fi first
#define se second

int n;
char a[101][101];
ii A, B;

int solve() {
    queue < ppi > q;
    q.push(mp(A, 0));

    set <ii> visit;
    visit.insert(A);

    while (!q.empty()) {
        ppi x = q.front(); q.pop();

        if (x.fi == B) return x.se;

        //cac diem phia tren x.fi 
        for (int i=x.fi.fi-1; i>=0; i--) {
            if (a[i][x.fi.se] == 'X')
                break;
            ii P (i, x.fi.se);
            if (visit.find(P) == visit.end()) {
                q.push(mp(P, x.se + 1));
                visit.insert(P);
            }
        }
        //cac diem phia duoi x.fi
        for (int i=x.fi.fi+1; i<n; i++) {
            if (a[i][x.fi.se] == 'X')
                break;
            ii P (i, x.fi.se);
            if (visit.find(P) == visit.end()) {
                q.push(mp(P, x.se + 1));
                visit.insert(P);
            }
        }
        //cac diem ben trai x.fi
        for (int i=x.fi.se-1; i>=0; i--) {
            if (a[x.fi.fi][i] == 'X')
                break;
            ii P (x.fi.fi, i);
            if (visit.find(P) == visit.end()) {
                q.push(mp(P, x.se + 1));
                visit.insert(P);
            }
        }
        //cac diem ben phai x.fi
        for (int i=x.fi.se+1; i<n; i++) {
            if (a[x.fi.fi][i] == 'X')
                break;
            ii P (x.fi.fi, i);
            if (visit.find(P) == visit.end()) {
                q.push(mp(P, x.se + 1));
                visit.insert(P);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    cin >> A.fi >> A.se >> B.fi >> B.se;

    cout << solve() << endl; 
}
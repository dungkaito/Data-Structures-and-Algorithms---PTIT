/*#include <bits/stdc++.h>
using namespace std;

struct pos{
    int x, y, huongTruocDo, soLanDoiHuong;
    pos(){}
    pos(int a, int b, int c, int d) {
        x=a; y=b; huongTruocDo=c; soLanDoiHuong=d; // hàm tạo
    }
};
queue <pos> q;
int n, m, sx, sy, tx, ty;
char s[505][505];
bool chuaxet[505][505][4][4]; // [x][y][huongTruocDo][soLanDoiHuong] - mảng đánh dấu vị trí đã duyệt
int dx[4] = {0,0,1,-1},
    dy[4] = {1,-1,0,0};
//huongTruocDo := (dựa theo mảng dx, dy)
//   0: phải     1: trái     2: xuóng     3: lên

void input() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') sx = i, sy = j;
            if (s[i][j] == 'T') tx = i, ty = j;
        }
}

bool check(pos t) {
    return (t.x>=0 && t.y>=0 && t.x<n && t.y<m && s[t.x][t.y] != '*' 
        && chuaxet[t.x][t.y][t.huongTruocDo][t.soLanDoiHuong]);
}

string solve() {
    memset(chuaxet, true, sizeof(chuaxet));

    while (!q.empty()) q.pop();
    for (int i=0; i<=3; i++) {
        q.push(pos(sx, sy, i, 0));
        chuaxet[sx][sy][i][0] = false;
    }

    while (!q.empty()) {
        pos t = q.front(); q.pop();

        for (int i=0; i<=3; i++) {
            pos tmp;

            if (i == t.huongTruocDo)
                tmp = pos(t.x + dx[i], t.y + dy[i], i, t.soLanDoiHuong);
            else 
                tmp = pos(t.x + dx[i], t.y + dy[i], i, t.soLanDoiHuong + 1);

            if (tmp.soLanDoiHuong == 3) continue;

            if (check(tmp)) {
                chuaxet[tmp.x][tmp.y][tmp.huongTruocDo][t.soLanDoiHuong] = false;
                q.push(tmp);
            }
        }
    }
    for (int i=0; i<=3; i++)
        for (int j=0; j<=2; j++)
            if (!chuaxet[tx][ty][i][j])
                return "YES\n";
    return "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        input();
        cout << solve();
    }
}sub WA*/
#include<bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair < int,int > pii;

int n,m,r1,c1,r2,c2;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char a[505][505];
int f[505][505];

void input(){
    cin >> n >> m; 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j ++){
            cin >> a[i][j];
            if ( a[i][j] == 'S') r1 = i , c1 = j;
            if ( a[i][j] == 'T') r2 = i , c2 = j;
        }
    }
}

bool move(){
    memset(f, -1, sizeof(f));
    queue< pii > q;
    auto enqueue = [&](int i, int j, int e) {
        if (f[i][j] == -1) {
        f[i][j] = e;
        q.push({i, j});
        }
    };
    enqueue(r1, c1, 0);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int r = u.first, c = u.second;
        if (f[r][c] > 3) return false;
        if (r == r2 && c == c2) return true;
        int e = f[r][c] + 1;
        for (int i = r; i <= n && a[i][c] != '*'; i++) enqueue(i, c, e);
        for (int i = r; i >= 1 && a[i][c] != '*'; i--) enqueue(i, c, e);
        for (int j = c; j <= m && a[r][j] != '*'; j++) enqueue(r, j, e);
        for (int j = c; j >= 1 && a[r][j] != '*'; j--) enqueue(r, j, e);
    }
    return false;
}

void solve(){
    cout <<  (move()? "YES" : "NO")  << endl;
}

int main(){
    int t; cin >> t;
    while (t--) { 
		input();
		solve();
	}
}
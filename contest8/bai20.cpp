#include <bits/stdc++.h>
using namespace std;

#define si pair<string, int>
#define fi first
#define se second

int l[10] = {3,0,2,7,4,1,6,8,5,9}, // xoay trái theo chiều thuận (chiều kim đông hồ)
    ld[10] = {1,5,2,0,4,8,6,3,7,9},// xoay trái theo chiều nghịch
    r[10] = {0,4,1,3,8,5,2,7,9,6}, // xoay phải theo chiều thuận
    rd[10] = {0,2,6,3,1,5,9,7,4,8};// xoay phải theo chiều nghịch

map <string, int> dem, flag_copy;
string a = "", b = "1238004765"; // a là cấu hình đề cho
queue <si> q;

string change(string u, int move[]) {
    string res; res.resize(10);
    for (int i=0; i<10; i++) 
        res[i] = u[move[i]];
    return res;
}

void check(string tmp, string u, int flag) {
    if (dem[tmp] == 0) { // chưa đc duyệt
        dem[tmp] = dem[u] + 1; // tăng 1 bước
        flag_copy[tmp] = flag;
        q.push(si(tmp, flag));
    }
    else {
        if (flag != flag_copy[tmp]) {
            cout << dem[tmp] + dem[u] - 1;
            exit(0); 
        }
    }
}

void solve() {
    // đánh dấu đã duyệt (giá trị là số bước)
    dem[a] = 1;
    dem[b] = 1;

    // flag = second = 1: xoay thuận, second = 0: xoay ngưỢc
    q.push(si(a, 1));
    q.push(si(b, 0));

    flag_copy[a] = 1;
    flag_copy[b] = 0;

    while (!q.empty()) {
        si t = q.front(); q.pop();
        string u = t.fi; int flag = t.se;

        string tmp;
        if (flag == 1) {
            tmp = change(u, l);// xoay phải thuận u
            check(tmp, u, flag);
            tmp = change(u, r);
            check(tmp, u, flag);
        }
        else { // flag == 0
            tmp = change(u, ld);
            check(tmp, u, flag);
            tmp = change(u, rd);
            check(tmp, u, flag);
        }
    }
}

int main() {
    int n; 
    for (int i=0; i<10; i++) {
        cin >> n;
        a += (n + '0');
    }
    solve();
    return 0;
}
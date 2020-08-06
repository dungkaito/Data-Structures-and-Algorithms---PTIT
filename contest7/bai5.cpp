/*open with vscode
0 1 2 3 4 5 6 7 8
( ) ( ( ) ) ) ) )
push vao stack :-1
duyệt xâu: 
    nếu gặp '('
        push index vào stack (-1 0)
    nếu gặp ')'
        pop stack ra (-1, hiểu là lấy '(' ra để đc 1 cặp)
        nếu pop xong mà empty
            thì push(index hiện tại vào, mean push ')'    )
        độ dài chuỗi con hợp lệ vừa tìm được: index đang duyệt (dấu đóng) - top
        ans = max (ans, result độ dài vừa tìm);
*/
#include <bits/stdc++.h>
using namespace std;
int solve(string s) {
    int ans = 0;
    stack<int> stk; stk.push(-1);
    for(int i=0; i<s.size(); i++) {
        if (s[i] == '(')
            stk.push(i);
        else {
            stk.pop();
            if (!stk.empty()) 
                ans = max(ans, i - stk.top());
            else stk.push(i);
        }
    }
    return ans;
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        cout << solve(s) << endl;
    }
}
/*open with vscode
3[a3[b]1[ab]]
2 stack: số và ký tự
duyệt từ trái -> phải
    nếu số push và stack số
    nếu ký tự khác dấu đóng
        push vào stack ký tự
    nêu ký tự đóng
        lấy từng ký tự trong stack kt ra cho đến [
        lấy 1 số trong stack số
        ...
*/
#include <bits/stdc++.h>
using namespace std;
string repeat(string s, int n) {
    string tmp = s;
    for (int i=2; i<=n; i++)
        s += tmp;
    return s;
}
void solve(string s) {
    int n = s.length();
    string res;
    stack <int> so;
    stack <char> kyTu;
    for (int i=0; i<n; i++) {
        if (isdigit(s[i])) {
            int tmp = 0;
            while (isdigit(s[i])) {
                tmp = tmp * 10 + s[i] - '0';
                i++;
            }
            i--;
            so.push(tmp);
        }
        else if (s[i] == ']') {
            string tmp;
            int lap;
            if (!so.empty()) {
                lap = so.top();
                so.pop();
            }
            while (!kyTu.empty() && kyTu.top() != '[') {
                tmp = kyTu.top() + tmp;
                kyTu.pop();
            }
            if (!kyTu.empty() && kyTu.top() == '[')
                kyTu.pop();
            for (int j=0; j<lap; j++)  
                res = res + tmp;
            for (int j=0; j<res.length(); j++)
                kyTu.push(res[j]);
            res = "";
        }
        else if (s[i] == '[') {
            if (isdigit(s[i-1])) 
                kyTu.push(s[i]);
            else {
                kyTu.push(s[i]);
                so.push(1);
            }
        }
        else kyTu.push(s[i]);
    }
    while (!kyTu.empty()) {
        res = kyTu.top() + res;
        kyTu.pop();
    }
    cout << res << endl;
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        solve(s);
    }
}
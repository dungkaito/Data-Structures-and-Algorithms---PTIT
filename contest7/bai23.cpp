/*open with vscode
3[a3[b]1[ab]]
duyệt từ phải -> trái
    nếu ']': push vào stack
    nêu chữ cái:
        lấy top ra //lấy b ra
        push vào s[i] + top // push vào ab
    nếu '[': 
        lấy top ra (1 xâu con)
        substr = top * s[i-1]
        nếu top là xâu -> lấy ra tiếp
        substr += top
        push substr
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
    stack <string> st;
    for (int i=n-1; i>=0; --i) {
        if (s[i] == ']')
            st.push(string(1, s[i]));
        else if (isalpha(s[i])) {
            if (st.top() != "]") {
                string top = st.top(); st.pop();
                st.push(string(1, s[i]) + top);
            }
            else st.push(string(1, s[i]));
        }
        else if (s[i] == '[') {
            string substr = st.top(); st.pop();
            st.pop(); // ]
            if (isdigit(s[i-1])) substr = repeat(substr, s[i-1] - '0');
            if (!st.empty() && st.top() != "]") {
                substr += st.top(); 
                st.pop();
            }
            st.push(substr);
        }
    }
    cout << st.top() << endl;
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        solve(s);
    }
}
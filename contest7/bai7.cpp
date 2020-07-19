/*open with vscode to read
)(())(((
loại bỏ những cặp ngoặc hợp lệ đi
=> stack còn lại )))..)(..(((
nửa bên trái (ngoặc đóng): 
    đổi chiều 1 nửa =>> nửa bên trái đúng
nửa bên phải
    đổi chiều 1 nửa =>> nửa ngoặc mở ban đầu này cũng thành hợp lệ
nếu nửa trái có lẻ phần tử: còn 1 dấu vẫn đóng(thiếu mở)
nếu nửa phải có lẻ phần tử: còn 1 dấu vẫn mở(thiếu đóng)
    đổi dồng thời 2 cái này sẽ có 1 cặp hợp lệ
*note: vì size luôn là chẵn nên nếu nửa trái lẻ thì
      nửa phải cũng lẻ.
code:
đếm số ngoặc đóng: dong;
đếm số ngoặc mở: mo = size-dong
kết quả: dong/2 + mo/2 + dong%2 (hoặc +mo%2, chỉ cần đổi 1 bên)
rút gọn: (dong+mo)/2 + dong%2
        =size/2 + dong%2
*/
#include <bits/stdc++.h>
using namespace std;
int solve (string s) {
    stack <char> stk;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(')
            stk.push(s[i]);
        else {
            if (stk.empty() || stk.top() == ')')
                stk.push(s[i]);
            else if (stk.top() == '(')
                stk.pop();
        }
    }
    int size = stk.size(), mo = 0;
    while (!stk.empty() && stk.top() == '('){
        stk.pop();
        mo++;
    }
    return size/2 + mo%2;
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        cout << solve(s) << endl;
    }
}
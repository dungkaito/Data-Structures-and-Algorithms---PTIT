/* open with vscode
s = "1234"  len = 4
F[i] là tổng các xâu con có chứa s[i]
F[0] = 1
F[1] = 2 + 12
F[2] = 3 + 23 + 123
F[3] = 4 + 34 + 234 + 1234
     = 4 + 30+4 + 230+4 + 1230+4
     = 4*4 + 10 * (3+23+123)
vậy F[i] = s[i]*(i+1) + 10*F[i-1]
cộng dồn tất cả phần tử của mảng F lại có ans 
nếu input len(s) lớn có thể khử mảng F
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long li;
string s;
li solve() {
    li ans = s[0]-'0';
    li current, previous = s[0]-'0';
    for (int i=1; i<s.size(); i++) {
        current = (s[i]-'0')*(i+1) + 10*previous;
        previous = current;
        ans += current;
    }
    return ans;
}
int main() {
    int t; cin>>t;
    while (t--) {
        cin>>s;
        cout<<solve()<<endl;
    }
}
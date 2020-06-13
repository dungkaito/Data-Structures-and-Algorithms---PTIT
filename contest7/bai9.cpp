/*open with vscode
s = "(1+(2*(3+4)))"
tìm index tất cả cặp ngoặc lưu vào pair(fi,se)
vd pair[0].fi = 0, 
   pair[0].se = 12;...
n = số cặp ngoặc
quay lui nhị phân ngược x[n-1] :
    xong 1 cấu hình x:
        hàm update
update:
    nếu x[] = 11111 thì return
    string res;
    for i = 0 -> s.size()-1 ;i++
        bool check = true
        for j = 0 -> n-1; j++
            nếu x[j]=0 và i == pair[j].fi hoặc se
                check = false;
                break; 
        if check = true thì res += s[i];
    cout << res
*/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

string s;
vector < pair<int, int> > bracket;
int countBrackets, x[11];
vector <string> result;

bool check(string str) {
    for (int i=0; i<str.size(); i++)
        if(str[i] == '/' && str[i+1] == '0')
            return false;
    if (result.size() > 0)
        for (int i=0; i<result.size(); i++)
            if (str == result[i])
                return false;
    return true;
}

void update() {
    int full1 = 1;
    for (int i=0; i<countBrackets; i++)
        if (x[i] == 0) {
            full1 = 0; break;
        }
    if (full1 == 1) return;
    
    string res;
    for (int i=0; i<s.length(); i++) {
        bool check = true;
        for (int j=0; j<countBrackets; j++) {
            if (x[j] == 0 && (i == bracket[j].fi || i == bracket[j].se)) {
                check = false;
                break;
            }
        }
        if (check == true) res += s[i];
    }
    if (check(res)) {
        result.push_back(res);
        // cout << res << endl;
    }
}

void Try(int i) {
    for (int j=1; j>=0; j--) {
        x[i] = j;
        if (i == countBrackets - 1)    
            update();
        else Try(i + 1);
    }
}

void findBrackets() {
    int n = s.length();
    stack <int> st;
    for (int i=0; i<n; i++)
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')')
            if (!st.empty()) {
                bracket.push_back(make_pair(st.top(), i));
                st.pop();
            }
    countBrackets = bracket.size();
    reverse(bracket.begin(), bracket.end());
    // for (int i=0; i<countBrackets; i++)
    //     cout<<bracket[i].fi<<" "<<bracket[i].se<<endl;
}

int main() {
    cin >> s;
    findBrackets();
    Try(0);
    sort(result.begin(), result.end());
    for (int i=0; i<result.size(); i++)
        cout << result[i] << endl;
}
#include <bits/stdc++.h>
using namespace std;
void solve(string seq) {
    string result; 
    stack<int> stk; 
    for (int i = 0; i <= seq.length(); i++) { 
        stk.push(i + 1);  
        if (i == seq.length() || seq[i] == 'I') { 
            while (!stk.empty()) { 
                result += to_string(stk.top());
                stk.pop(); 
            } 
        } 
    }
    cout << result << endl; 
}
int main() {
    int t; cin >> t;
    string s;
    while (t--) {
        cin >> s;
        solve(s);
    }
}
#include <bits/stdc++.h> 
using namespace std;
string solve(stack<char> stk, string s) {
    for (int i=0; i<s.size(); i++)
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);
        else {
            if (stk.empty()) 
                return "NO";
            if (s[i] == ')')
                if (stk.top() == '(') stk.pop();
                else return "NO";
            else if (s[i] == ']')
                if (stk.top() == '[') stk.pop();
                else return "NO";
            else if (s[i] == '}')
                if (stk.top() == '{') stk.pop();
                else return "NO";
        }
    return "YES";
}
int main() {
    int t; cin >> t;
    string s;
    stack<char> stk;
    while (t--) {
        cin >> s;
        cout << solve(stk, s) <<endl;
    }
}
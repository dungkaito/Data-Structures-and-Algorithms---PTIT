#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    string s;
    stack <char> stk;
    while (t--) {
        getline(cin >> ws, s);
        for (int i=0; i<=s.size(); i++)
            if (s[i] == ' ' || i == s.size()) {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << " ";
            }
            else {
                stk.push(s[i]);
            }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
void showStack(stack <int> stk) {
    if (stk.empty()) {
        cout << "empty\n";
        return;
    }
    vector<int> res;
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    for(int i=res.size()-1; i>=0; i--)
        cout << res[i] << " ";
    cout << endl;
}
int main() {
    string s;
    stack <int> stk;
    while (cin>>s) {
        if (s == "push") {
            int n; cin >> n;
            stk.push(n);
        }
        else if (s == "pop") {
            if (!stk.empty())
                stk.pop();
        }
        else if (s == "show") {
            showStack(stk);
        }
    }
}
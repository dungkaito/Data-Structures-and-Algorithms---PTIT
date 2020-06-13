#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q; cin >> Q;
    string s;
    stack <int> stk; 
    while (Q--) {
        cin >> s;
        if (s == "PRINT") {
            if (stk.empty()) 
                cout << "NONE\n";
            else 
                cout << stk.top() << endl;
        }   
        else if (s == "POP"){
            if (!stk.empty())
                stk.pop();
        }
        else { // push
            int tmp; cin >>tmp;
            stk.push(tmp);
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q; cin >> Q;
    deque <int> dq;
    string s;
    while (Q--) {
        cin >> s;
        if (s == "PUSHFRONT") {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if (s == "PRINTFRONT") {
            if (dq.empty()) cout << "NONE\n";
            else cout << dq.front() << endl;
        }
        else if (s == "POPFRONT") {
            if (!dq.empty()) dq.pop_front();
        }
        else if (s == "PUSHBACK") {
            int x; cin >> x;
            dq.push_back(x);
        } 
        else if (s == "PRINTBACK") {
            if (dq.empty()) cout << "NONE\n";
            else cout << dq.back() << endl;
        }
        else {
            if (!dq.empty()) dq.pop_back();
        }
    }
}
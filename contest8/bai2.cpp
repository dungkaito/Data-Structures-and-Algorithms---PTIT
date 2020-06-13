#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q; cin >> Q;
    queue <int> q;
    string s;
    while (Q--) {
        cin >> s;
        if (s == "PUSH") {
            int x; cin >> x;
            q.push(x);
        }
        else if (s == "PRINTFRONT") {
            if (q.empty()) cout << "NONE\n";
            else cout << q.front() << endl;
        }
        else {
            if (!q.empty()) q.pop();
        }
    }
}
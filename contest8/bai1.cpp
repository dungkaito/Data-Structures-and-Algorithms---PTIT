#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    int t, n, key; cin >> t;
    while (t--) {
        queue <int> q;
        cin >> n;
        while (n--) {
            cin >> key;
            switch (key) {
                case 1: {
                    cout << q.size() << endl;
                    break;
                }
                case 2: {
                    if (q.empty()) cout << "YES\n";
                    else cout << "NO\n";
                    break;
                }
                case 3: {
                    int num; cin >> num;
                    q.push(num);
                    break;
                }
                case 4: {
                    if (!q.empty()) q.pop();
                    break;
                }
                case 5: {
                    if (!q.empty()) cout << q.front() << endl;
                    else cout << "-1\n";
                    break;
                }  
                case 6: {
                    if (!q.empty()) cout << q.back() << endl;
                    else cout << "-1\n";
                    break;
                }
            } // end of switch-case
        } // end of while n
    } // end of while t
} // end of main()
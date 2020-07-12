#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        vector <int> v;
        map <int, int> m;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (m.find(cha) == m.end()) {
                v.push_back(cha);
                m[cha] = 1;
            }
            if (m.find(con) == m.end()) {
                v.push_back(con);
                m[con] = 1;
            }
        }
        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
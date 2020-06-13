#include <bits/stdc++.h> 
using namespace std;
int main() {
    int n, v;
    string s;
    vector <int> dsk[55];

    cin >> n; cin.ignore();
    for (int i=1; i<=n; i++) {
        getline(cin, s);
        istringstream iss (s);
        while (iss >> v) dsk[i].push_back(v);
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j<dsk[i].size(); j++) {
            if (dsk[i][j] > i) 
                cout << i << " " << dsk[i][j] << endl;
        }
    }
}
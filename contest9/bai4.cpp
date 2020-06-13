#include <bits/stdc++.h>
using namespace std;
int mtk[1005][1005] = {0};
int main() {
    int n, v; 
    cin >> n; cin.ignore();
    string s;
    for (int i=1; i<=n; i++) {
        getline(cin, s);
        istringstream iss (s);
        while (iss >> v) mtk[i][v] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << mtk[i][j] << " ";
        }
        cout << endl;
    }
}
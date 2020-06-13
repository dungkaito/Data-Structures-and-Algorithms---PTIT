#include <bits/stdc++.h>
using namespace std;

vector <int> dsk[1005];
bool chuaxet[1005];
int truoc[1005];

void dfs(int u) {
    chuaxet[u] = false;
    for (int i=0; i<dsk[u].size(); i++) {
        int v = dsk[u][i];
        if (chuaxet[v]) {
            truoc[v] = u;
            dfs(v);
        }
    }
}

void inDuongDi(int u, int v) {
    stack <int> st;
    st.push(v);
    while (st.top() != u) {
        st.push(truoc[st.top()]);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main() {
    int t, dinh, canh, u, v, a, b; cin >> t;
    while (t--) {
        cin >> dinh >> canh >> u >> v;
        for (int i=1; i<=dinh; i++) dsk[i].clear();
        for (int i=1; i<=canh; i++) {
            cin >> a >> b;
            dsk[a].push_back(b);
        }

        memset(chuaxet, true, sizeof(chuaxet));
        dfs(u);

        if (chuaxet[v]) cout << "-1\n";
        else inDuongDi(u, v);
    }
}
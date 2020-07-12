#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

int check(Node *root) {
    // kiểm tra: các node trung gian đều có 2 con
    if (!root) return 1;
    Node *l = root->left, *r = root->right;
    if (!l && !r) return 1;
    if ((!l && r) || (l && !r)) return 0;
    return (check(l) && check(r));
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        // build tree
        Node *parent, *child, *root = NULL;
        map <int, Node*> m;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (m.find(cha) == m.end()) {
                parent = new Node(cha);
                m[cha] = parent;
                if (!root) root = parent;
            }
            else parent = m[cha];
            child = new Node(con);
            if (ch == 'L') parent->left = child;
            else parent->right = child;
            m[con] = child;
        }
        // solve
        cout << check(root) << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

bool check1(Node *root) {
    // kiểm tra cây nhị phân đúng (node trung gian có 2 node con)
    if (!root) return true;
    Node *l = root->left, *r = root->right;
    if ((!l && r) || (l && !r)) return false;
    return (check1(l) && check1(r));
} 

bool check2(Node *root, int level, int leafLevel) {
    // kiểm tra các node lá có cùng mức hay không
    if (!root) return true;
    Node *l = root->left, *r = root->right;
    if (!l && !r) {
        if (leafLevel == 0) {
            leafLevel = level;
            return true;
        }
        return level == leafLevel;
    }
    return check2(l, level+1, leafLevel) && check2(r, level+1, leafLevel);
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        // build tree
        Node *root = NULL, *parent, *child;
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
        if (check1(root) && check2(root, 0, 0))
            cout << "Yes\n";
        else cout << "No\n";
    }  
}
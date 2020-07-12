#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

int maxPathSum(Node *root, int &res) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return root->data;
    int ls = maxPathSum(root->left, res);
    int rs = maxPathSum(root->right, res);
    if (root->left && root->right) {
        res = max(res, ls + rs + root->data);
        return max(ls, rs) + root->data;
    }
    return (!root->left) ? rs+root->data : ls+root->data;
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        Node *root = NULL, *parent, *child;
        map <int, Node*> m;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (m.find(cha) == m.end()) {
                parent = new Node(cha);
                m[cha] = parent;
                if (root == NULL) root = parent;
            }
            else parent = m[cha];
            child = new Node(con);
            if (ch == 'L') parent->left = child;
            else parent->right = child;
            m[con] = child;
        }
        int res = INT_MIN;
        maxPathSum(root, res);
        cout << res << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;  
    }
};

void leftLeafSum(Node *root, bool dir, int &sum) {
    if (!root) return;
    if (dir && !root->left && !root->right) 
        sum += root->data;
    leftLeafSum(root->left, true, sum);
    leftLeafSum(root->right, false, sum);
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
        int sum = 0;
        leftLeafSum(root, true, sum);
        cout << sum << endl;
    }
}
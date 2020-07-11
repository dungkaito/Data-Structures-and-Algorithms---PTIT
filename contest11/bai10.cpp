#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

int sum(Node *root) {
    if (root == NULL) return 0;
    else {
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        return (root->data + leftSum + rightSum);
    }
}

int isSumTree(Node *root) {
    if (!root)  return 1;
    if (!root->left && !root->right) return 1;

    int leftTree = sum(root->left);
    int rightTree = sum(root->right);

    if (root->data == leftTree + rightTree && isSumTree(root->left) && isSumTree(root->right))
        return 1;
    return 0;
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        // build tree    
        Node *root = NULL, *parent, *child;
        map <int, Node*> m; // map<giá trị, node tương ứng>
        
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
        cout << isSumTree(root) << endl;
    }
}
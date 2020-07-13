#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    Node *left, *right;
    Node(int val) {
        data = val; left = right = NULL;
    }
};

Node *build(Node *root, int val) {
    if (!root) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) 
        root->left = build(root->left, val);
    else
        root->right = build(root->right, val);
    return root;
}

void inOrder(Node *root) {
    if (root) {
        cout << root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        vector <int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        // build tree from level-order BST 
        Node *root = new Node(v[0]);
        for (int i=1; i<n; i++)
            root = build(root, v[i]);
        // output
        inOrder(root);
        cout << endl;
    }
}
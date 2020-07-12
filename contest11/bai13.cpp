#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

void makeNode(Node *root, int cha, int con, char ch) {
    if (ch == 'L') root->left = new Node(con);
    else root->right = new Node(con);
}

void insert(Node *root, int cha, int con, char ch) {
    if (!root) return;
    if (root->data == cha)
        makeNode(root, cha, con, ch);
    else {
        insert(root->left, cha, con, ch);
        insert(root->right, cha, con, ch);
    }
}

int isIdentical(Node *a, Node *b) {
    if (!a && !b) return 1;
    if (a && b) return (a->data == b->data && isIdentical(a->left, b->left) && isIdentical(a->right, b->right));
    return 0;
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        // build tree
        cin >> n;
        Node *root1 = NULL;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (!root1) {
                root1 = new Node(cha);
                makeNode(root1, cha, con, ch);
            }
            else insert(root1, cha, con, ch);
        }

        cin >> n;
        Node *root2 = NULL;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (!root2) {
                root2 = new Node(cha);
                makeNode(root2, cha, con, ch);
            }
            else insert(root2, cha, con, ch);
        }
        
        // solve
        cout << isIdentical(root1, root2) << endl;
    }
}
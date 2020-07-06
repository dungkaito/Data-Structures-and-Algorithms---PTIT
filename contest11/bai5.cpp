#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

void makeNote(Node *root, int cha, int con, char ch) {
    if (ch == 'L')
        root->left = new Node(con);
    else
        root->right = new Node(con);
}

void insert(Node *root, int cha, int con, char ch) {
    if (root == NULL) return;
    if (root->data == cha)
        makeNote(root, cha, con, ch);
    else {
        insert(root->left, cha, con, ch);
        insert(root->right, cha, con, ch);
    }
}

void levelOrder(Node *root) {
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *t = q.front(); q.pop();
        cout << t->data << " ";
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        Node *root = NULL;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (root == NULL) {
                root = new Node(cha);
                makeNote(root, cha, con, ch);
            }
            else insert(root, cha, con ,ch);
        }
        levelOrder(root);
        cout << endl;
    }
}
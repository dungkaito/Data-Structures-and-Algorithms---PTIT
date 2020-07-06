#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL;
    }
};

void makeNode (Node *root, int cha, int con, char ch) {
    if (ch == 'L')
        root->left = new Node(con);
    else root->right = new Node(con);
}

void insert (Node *root, int cha, int con, char ch) {
    if (root == NULL) return;
    if (root->data == cha)
        makeNode(root, cha, con, ch);
    else {
        insert(root->left, cha, con, ch);
        insert(root->right, cha, con, ch);
    }
}

int height (Node *root) {
    if (!root) return 0;
    return (1 + max(height(root->left), height(root->right)));
}

bool check (Node *root, int level, int h) {
    if (!root) return true;
    if (!root->left && !root->right && level < h) return false;
    return check(root->left, level+1, h) && check(root->right, level+1, h);
}

int main() {
    int t, n, cha, con; cin >> t;
    char ch;
    while (t--) {
        cin >> n;
        Node *root = NULL;
        for (int i=1; i<=n; i++) {
            cin >> cha >> con >> ch;
            if (root == NULL) {
                root = new Node(cha);
                makeNode(root, cha, con, ch);
            }
            else
                insert(root, cha, con, ch);
        }
        // kiểm tra node lá cùng mức
        cout << check(root, 1, height(root)) << endl;
    }
}
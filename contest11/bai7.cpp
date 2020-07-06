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

void spiralOrder(Node *root) {
    stack <Node*> st1, st2;
    st1.push(root);
    Node *tmp;
    while (!st1.empty() || !st2.empty()) {
        while (!st1.empty()) {
            tmp = st1.top(); st1.pop();
            cout << tmp->data << " ";
            if (tmp->right) st2.push(tmp->right);
            if (tmp->left) st2.push(tmp->left);
        }
        while (!st2.empty()) {
            tmp = st2.top(); st2.pop();
            cout << tmp->data << " ";
            if (tmp->left) st1.push(tmp->left);
            if (tmp->right) st1.push(tmp->right);
        }
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
        spiralOrder(root);
        cout << endl;
    }
}
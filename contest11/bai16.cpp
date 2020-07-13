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
    if (ch == 'L')
        root->left = new Node(con);
    else
        root->right = new Node(con);
}

void insert(Node *root, int cha, int con, char ch) {
    if (root == NULL) return;
    if (root->data == cha)
        makeNode(root, cha, con, ch);
    else {
        insert(root->left, cha, con, ch);
        insert(root->right, cha, con, ch);
    }
}

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
        Node *root = NULL;
        for (int i=0; i<n; i++) {
            cin >> cha >> con >> ch;
            if (root == NULL) {
                root = new Node(cha);
                makeNode(root, cha, con, ch);
            }
            else insert(root, cha, con ,ch);
        }
        int res = INT_MIN;
        maxPathSum(root, res);
        cout << res << endl;
    }
}
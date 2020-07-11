#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x; left = right = NULL; 
    }
};

Node* creatBST(int start, int end) {
    if (start > end) return NULL;
    
    int mid = (start + end) / 2;

    Node *temp = new Node(a[mid]);
    temp->left = creatBST(start, mid - 1);
    temp->right = creatBST(mid + 1, end);

    return temp;
}

void preOrder(Node *root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        Node *root = creatBST(0, n-1); //build tree

        preOrder(root); //traversal
        cout << endl;
    }
}
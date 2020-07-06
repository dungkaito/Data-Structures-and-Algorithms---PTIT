#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *left, *right;
    Node (string s) {
        data = s;
        left = right = NULL;
    }
};

Node *buildTree(string s[], int n) {
    Node *root = new Node(s[0]);
    int index = 1;
    queue <Node*> q;
    q.push(root);
    Node *par, *l, *r;
    while (!q.empty()) {
        par = q.front(); q.pop();

        if (index < n) {
            l = new Node(s[index]);
            index++;
            par->left = l;    
            q.push(l);
        }
        else par->left = NULL;

        if (index < n) {
            r = new Node(s[index]);
            index++;
            par->right = r;
            q.push(r);
        }
        else par->right = NULL;
    }
    return root;
}

long long toNum(string s) {
    long long ans = 0;
    if (s[0] == '-') {
        for (int i=1; i<s.length(); i++) {
            ans = ans * 10 + s[i] - '0';
            return -ans;
        }
    }
    for (int i=0; i<s.length(); i++)
        ans = ans * 10 + s[i] - '0';
    return ans;
}

long long computeTree(Node *t) {
    if (t->left == NULL && t->right == NULL)
        return toNum(t->data);
    if (t->data == "+")
        return computeTree(t->left) + computeTree(t->right);
    if (t->data == "-")
        return computeTree(t->left) - computeTree(t->right);
    if (t->data == "*")
        return computeTree(t->left) * computeTree(t->right);
    return computeTree(t->left) / computeTree(t->right);
}

int main() {
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        string s[n];
        for (int i=0; i<n; i++) cin >> s[i];

        Node *t = buildTree(s, n);
        cout << computeTree(t) << endl;
    }
}
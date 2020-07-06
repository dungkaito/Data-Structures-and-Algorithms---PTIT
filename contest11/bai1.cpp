#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

bool toanTu(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

Node *creatNode(char c) {
    Node *res = new Node;
    res->data = c;
    res->left = res->right = NULL;
    return res;
}

Node *buildTree(string hauTo) {
    stack <Node*> st;
    Node *par, *l, *r;
    for (int i=0; i<hauTo.length(); i++) {
        if (!toanTu(hauTo[i]))
            st.push(creatNode(hauTo[i]));
        else {
            par = creatNode(hauTo[i]);

            r = st.top(); st.pop();
            l = st.top(); st.pop();

            par->left = l; par->right = r;

            st.push(par);
        }
    }
    return st.top();
}

void duyetGiua(Node *t) {
    if (t != NULL) {
        duyetGiua(t->left);
        cout << t->data << " ";
        duyetGiua(t->right);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        string hauTo; cin >> hauTo;
        Node *t = buildTree(hauTo);
        duyetGiua(t);
        cout << endl;
    }
}
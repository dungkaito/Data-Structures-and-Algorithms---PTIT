#include <bits/stdc++.h>
using namespace std;

int n;

int search(int val, int in[], int st, int en) {
    for (int i=st; i<=en; i++)
        if (in[i] == val)
            return i;
    return -1;
}

int findRoot(int in[], int level[], int st, int en) {
    for (int i=0; i<n; i++) {
        int tmp = search(level[i], in, st, en);
        if (tmp != -1) 
            return tmp;
    }
    return -1;
}

void printPostOrder(int in[], int level[], int start, int end) {
    if (start > end) return;
    int rootIndex = findRoot(in, level, start, end);
    printPostOrder(in, level, start, rootIndex-1);
    printPostOrder(in, level, rootIndex+1, end);
    cout << in[rootIndex] << " ";
}

int main() {
    int t; cin >> t;
    int in[1005], level[1005];
    while (t--) {
        cin >> n;;
        for (int i=0; i<n; i++) cin >> in[i];
        for (int i=0; i<n; i++) cin >> level[i];
        printPostOrder(in, level, 0, n-1);
        cout << endl;
    }
}
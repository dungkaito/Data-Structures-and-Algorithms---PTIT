#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[101], i, j, key;
    cin >> n;
    for (i=0; i<n; i++) cin >> a[i];
    cout<<"Buoc 0: "<<a[0]<<endl;
    for (i=1; i<n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        cout <<"Buoc "<< i << ": ";
        for (int k=0; k<=i; k++) cout<<a[k]<<" ";
        cout<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a[101], i, j, swapped;
    cin >> n; 
    for (i=0; i<n; i++) cin >> a[i];
    for (i=0; i<n; i++) {
        swapped = 0;
        for (j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap (a[j], a[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;
        cout<<"Buoc "<<i+1<<": ";
        for (j=0; j<n; j++) cout<<a[j]<<" ";
        cout<<endl;
    }
}
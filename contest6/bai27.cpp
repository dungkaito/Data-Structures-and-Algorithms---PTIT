#include <bits/stdc++.h>
using namespace std;
int main() {
    int indexOfMinElement, i, j, n, a[101];
    cin >> n;
    for (i=0; i<n; i++) cin >> a[i];
    for (i=0; i<n-1; i++) {
        indexOfMinElement = i;
        for (j=i+1; j<n; j++)
            if (a[indexOfMinElement] > a[j])
                indexOfMinElement = j;
        swap(a[i], a[indexOfMinElement]);
        cout <<"Buoc "<< i+1 << ": ";
        for (j=0; j<n; j++) cout<<a[j]<<" ";
        cout<<"\n";
    } 
}
#include <bits/stdc++.h>
using namespace std;
int a[1000001], n;
int partition (int start, int end) {
    int pivot = a[end], pIndex = start;
    for (int i=start; i<end; i++)
        if (a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    swap(a[pIndex], a[end]);
    return pIndex;

}
void quickSort (int start, int end) {
    if (start < end) {
        int pIndex = partition(start, end);
        quickSort(start, pIndex - 1);
        quickSort(pIndex + 1, end);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        quickSort(0, n-1);
        for (int i=0; i<n; i++) cout << a[i] <<" ";
        cout<<"\n";
    }
}
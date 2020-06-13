#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];
void merge (int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2], i, j, k;
    for (i=0; i<n1; i++) L[i] = a[i+left];
    for (j=0; j<n2; j++) R[j] = a[j+mid+1];
    i=0; j=0; k=left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
void mergeSort (int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        mergeSort(0, n-1);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}
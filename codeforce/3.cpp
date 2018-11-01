#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[100005];
int n;
void merge(int s, int m, int e) {
    int n1 = m-s+1;
    int n2 = e-m;
    int *left = (int *)malloc(n1*sizeof(int));
    int *right = (int *)malloc(n2*sizeof(int));
    for (int i = 0; i < n1; i++)
        left[i] = a[s+i];
    for (int i = 0; i < n2; i++)
        right[i] = a[m+1+i];
    int i, j, k;
    i = j = 0;
    k = s;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }
    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
    free(left);
    free(right);
}
void merge_sort(int s, int e) {
    if (s < e) {
        int mid = (s+e) >> 1;
        merge_sort(s, mid);
        merge_sort(mid+1, e);
        merge(s, mid, e);
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n-1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
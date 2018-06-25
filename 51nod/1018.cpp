#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 50005;
int a[maxn];
void sort(int l, int r) {
    if (l > r) return;
    int temp = a[l];
    int i = l, j = r;
    while (i != j) {
        while (a[j] >= temp && i < j) j--;
        while (a[i] <= temp && i < j) i++;
        if (i < j) swap(a[i], a[j]);
    }
    a[l] = a[i];
    a[i] = temp;
    sort(l, i-1);
    sort(i+1, r);
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(0, n-1);
    for (int i = 0; i < n; i++) printf("%d\n", a[i]);
    return 0;
}
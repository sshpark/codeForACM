#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
#define ll long long
struct node {
    int val;
    int pos;
}a[25];
bool cmp(node u, node v) {
    return u.val < v.val;
}
int main(int argc, char const *argv[])
{
    int n, b[25];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].val);
        a[i].pos = i;
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i++)
        b[a[i].pos] = a[(i+1)%n].val;
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}
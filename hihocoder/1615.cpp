#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node {
    int b, c;
}temp[205];
bool cmp(node a, node b) {
    return a.b < b.b;
}
int main(int argc, char const *argv[])
{
    int n, a[205][205], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            temp[i].b += a[j][i];
            temp[i].c += -a[j][i];
    }
    sort(temp, temp+n, cmp);
    for (int i = 1; i < n; i+=2)
        if (temp[i].b+temp[i-1].b < temp[i].c+temp[i-1].c)
            sum += temp[i].c+temp[i-1].c-temp[i].b-temp[i-1].b;
    printf("%d\n", sum);
    return 0;
}
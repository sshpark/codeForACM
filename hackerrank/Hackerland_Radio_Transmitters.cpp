#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int vis[maxn], a[maxn];
int main(int argc, char const *argv[])
{
    int n, k, x, cnt = 0;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (vis[x] == 0) {
            vis[x] = 1;
            a[cnt++] = x;
        }
    }

    sort(a, a+cnt);

    int res = 0, id = 0;

    while (id < cnt) {
        int tmp = a[id]+k;
        int i = id;
        res++;
        while (i < cnt && a[i] <= tmp) {
            id = i;
            i++;
        }
        tmp = a[id]+k;
        i = id;
        while (i < cnt && a[i] <= tmp) {
            id = i;
            i++;
        }
        id++;
    }
    printf("%d\n", res);

    return 0;
}

// 2 4 5 6 9 12 15
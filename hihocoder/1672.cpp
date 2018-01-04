#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 1000005;
int arr[maxn<<2], lazy[maxn<<2];
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) {
        arr[rt] = 0;
        return ;
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
}
void pushDown(int rt) {
    if (lazy[rt]) {
        arr[rt<<1] = arr[rt<<1|1] = lazy[rt];
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void update(int val, int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        arr[rt] = val;
        return;
    }
    pushDown(rt);
    int m = (l+r)>>1;
    if (L <= m) update(val, L, R, lson);
    if (R > m) update(val, L, R, rson);

}
int main(int argc, char const *argv[])
{
    int n, a, b;
    scanf("%d", &n);
    build(1, n, 1);
    while(n--) {
        scanf("%d %d", &a, &b);
        update(1, a, b, 1, 1000000, 1);
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= 5; i++)
        printf("%d", arr[i]);
    for (int i = 1; i <= 1000000; i++) {
        if (arr[i]) cnt++;
        else {
            if (cnt == 1) ans++;
            else if (cnt >= 2) ans += 2;
            cnt = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
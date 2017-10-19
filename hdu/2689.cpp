#include <stdio.h>
#include <iostream>
#include <string.h>
#include <netinet/in.h>
using namespace std;
const int maxn = 100005;
int n, tree[maxn];
inline int lowbit(int i) {
    return i & (-i);
}
inline void update(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += lowbit(i);
    }
}
inline int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d", &n)) {
        int ans = 0, a;
        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            update(a, 1);
            ans += i - query(a);
        }
        printf("%d\n", ans);
    }
    return 0;
}
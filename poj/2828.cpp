#include <stdio.h>
const int maxn = 200005;
int res[maxn], tree[maxn<<2], pos[maxn], val[maxn], id;
void build(int l, int r, int rt) {
    tree[rt] = r-l+1;
    if (l == r) return;
    int m = (l+r) >> 1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
}
void update(int l, int r, int rt, int p) {
    tree[rt]--;
    if (l == r) {
        id = l;
        return ;
    }
    int m = (l+r) >> 1;
    if (tree[rt<<1] >= p) update(l, m, rt<<1, p);
    else {
        p -= tree[rt<<1];
        update(m+1, r, rt<<1|1, p);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    
    while (~scanf("%d", &n)) {
        build(1, n, 1);
        for (int i = 0; i < n; i++)
            scanf("%d %d", pos+i, val+i);
        for (int i = n-1; i >= 0; i--) {
            update(1, n, 1, pos[i]+1);
            res[id] = val[i];
        }
        printf("%d", res[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", res[i]);
        printf("\n");
    }
    return 0;
}
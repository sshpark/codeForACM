#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 200005;
int pre[maxn], real[maxn], cnt[maxn], sum[maxn];
int n, m, vnum;
inline void init() {
    vnum = n;
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
        real[i] = i;
        sum[i] = i;
        cnt[i] = 1;
    }
}

int findx(int x) {
    return pre[x] == x ? x : pre[x] = findx(pre[x]);
}

inline void unin(int x, int y) {
    x = findx(real[x]), y = findx(real[y]);
    pre[x] = y;
    sum[y] += sum[x];
    cnt[y] += cnt[x];
}

inline void move(int a) {
    int t = findx(real[a]);
    sum[t] -= a, cnt[t] -= 1;
    real[a] = ++vnum;
    sum[real[a]] = a;
    cnt[real[a]] = 1, pre[real[a]] = real[a];
}


int main(int argc, char const *argv[])
{
    int a, b, c;
    while (~scanf("%d %d", &n, &m)) {
        init();
        while (m--) {
            scanf("%d", &a);
            if (a == 1) {
                scanf("%d %d", &b, &c);
                if (findx(real[b]) != findx(real[c]))
                    unin(b, c);
            }
            else if (a == 2) {
                scanf("%d %d", &b, &c);
                if (findx(real[b]) != findx(real[c]))
                    move(b), unin(b, c);
            }
            else {
                scanf("%d", &b);
                int tmp = findx(real[b]);
                printf("%d %d\n", cnt[tmp], sum[tmp]);
            }
        }
    }
    return 0;
}
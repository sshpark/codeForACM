#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 200005;
int pre[maxn], sum[maxn], n, m;
inline void init() {
    for (int i = 0; i <= n; i++) {
        pre[i] = i;
        sum[i] = 0;
    }
}
int findx(int x) {
    if (pre[x] == x) return x;
    int t = pre[x];
    pre[x] = findx(pre[x]);
    sum[x] += sum[t];
    return pre[x];
}
int main(int argc, char const *argv[])
{
    int a, b, c, fa, fb;
    while (~scanf("%d %d", &n, &m)) {
        init();
        int ans = 0;
        while (m--) {
            scanf("%d %d %d", &a, &b, &c);
            fa = findx(a-1);
            fb = findx(b);
            if (fa == fb) {
                if (sum[b] - sum[a-1] != c)
                    ans++;
            } else {
                if (fa < fb) {
                    pre[fb] = fa;
                    sum[fb] = sum[a-1] - sum[b] + c;
                } else {
                    pre[fa] = fb;
                    sum[fa] = sum[b] - sum[a-1] - c;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
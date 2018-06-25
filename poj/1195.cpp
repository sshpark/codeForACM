#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1025;
int c[maxn][maxn];
int n;
inline int lowbit(int x) {
    return x & (-x);
}
inline void add(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            c[i][j] += val;
}
inline int getsum(int x, int y) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            sum += c[i][j];
    return sum;
}
int main(int argc, char const *argv[])
{
    int x, a, b, d;
    memset(c, 0, sizeof c);
    scanf("%d %d", &x, &n);

    while (~scanf("%d", &x) && x != 3) {
        if (x == 1) {
            scanf("%d %d %d", &a, &b, &x);

            add(a+1, b+1, x);
        } else {
            scanf("%d %d %d %d", &a, &b, &x, &d);
            a++, b++, x++, d++;
            printf("%d\n", getsum(x, d)-getsum(x, b-1)-getsum(a-1, d)+getsum(a-1, b-1));
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 500005;
ll a[maxn], t[maxn];
int n;
ll sum = 0, tot = 0, ans = 0, cnt = 0;
inline int lowbit(int x) {
    return x & (-x);
}
inline void add(int x) {
    cnt++;
    while (x <= n) {
        t[x]++;
        x += lowbit(x);
    }
}
inline int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += t[x];
        x -= lowbit(x);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        sum += a[i];
    }
    if (sum % 3) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        tot += a[i];
        if (tot == sum/3*2 && i != n) add(i);
    }
    tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += a[i];
        if (tot == sum/3) ans += cnt - query(i);
    }
    printf("%lld\n", ans);
    return 0;
}
#include <iostream>
#include <cmath>
#include <string.h>
#define ll long long
using namespace std;
const int maxn = 10005;
bool isp[maxn];
int _p[maxn], e[maxn], cnt = 0;
void shai() {
    memset(isp, true, sizeof isp);
    for (int i = 2; i < maxn; i++)
        if (isp[i]) {
            _p[cnt++] = i;
            for (ll j = i*i; j < maxn; j += i)
                isp[j] = false;
        }
}
void add(int x, int f) {
    for (int i = 0; i < cnt; ++i) {
        if (_p[i] > x) break;
        while (x % _p[i] == 0) {
            x /= _p[i];
            e[i] += f;
        }
    }
}
void add_fac(int x, int f) {
    for (int i = 1; i <= x; i++)
        add(i, f);
}
int main(int argc, char const *argv[])
{
    int p, q, r, s;
    shai();
    while (~scanf("%d %d %d %d", &p, &q, &r, &s)) {
        memset(e, 0, sizeof e);
        add_fac(p, 1); add_fac(p-q, -1); add_fac(q, -1);
        add_fac(r, -1); add_fac(r-s, 1); add_fac(s, 1);
        double ans = 1;
        for (int i = 0; i < cnt; i++)
            ans *= pow(_p[i], e[i]);
        printf("%.5lf\n", ans);
    }
    return 0;
}
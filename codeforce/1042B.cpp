#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, d;
    int ta, tb, tc, a, b, c, tabc;
    ta = tb = tc = a = b = c = tabc = 10000000;
    char str[5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &d, str);
        int len = strlen(str);
        sort(str, str+len);
        if (len == 1) {
            if (str[0] == 'A') a = min(a, d);
            else if (str[0] == 'B') b = min(b, d);
            else c = min(c, d);
        } else if (len == 2) {
            if (str[0] == 'A' && str[1] == 'B') tc = min(tc, d);
            else if (str[0] == 'A' && str[1] == 'C') tb = min(tb, d);
            else ta = min(ta, d);
        } else {
            tabc = min(tabc, d);
        }
    }
    int ans1 = a+b+c;
    int ans2 = min(a+ta, min(b+tb, c+tc));
    int ans3 = min(ta+tc, min(tc+tb, ta+tb));
    int ans = min(ans1, min(tabc, min(ans3, ans2)));
    if (ans >= 10000000) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}
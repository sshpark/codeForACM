#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    while (~scanf("%d", &n)) {
        long long ans = 0;
        int top = 0;
        int st[80005];
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            while (top > 0 && st[top] <= x) top--;
            ans += top;
            st[++top] = x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1005
int a[N], dp[N];
int main(int argc, char const *argv[])
{
    int n, m;
    while(~scanf("%d", &n) && n) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) scanf("%d", a+i);
        scanf("%d", &m);
        if(m<5) {
            printf("%d\n", m);
            continue;
        }
        m -= 5;
        sort(a+1, a+n+1);
        for(int i = 1; i < n; i++)
            for(int j = m; j >= a[i]; j--)
                dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
        printf("%d\n", m+5-dp[m]-a[n]);
    }
    return 0;
}
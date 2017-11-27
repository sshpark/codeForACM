#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[5005];
int main(int argc, char const *argv[])
{
    int n, a[105], sum = 0;
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i), sum+=a[i];
    for (int i = 0; i < n; i++)
        for (int j = sum/2; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
    printf("%d\n", sum-2*dp[sum/2]);
    return 0;
}

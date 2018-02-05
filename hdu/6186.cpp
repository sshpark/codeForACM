#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int sum[maxn], sum1[maxn], sum2[maxn], rsum[maxn], rsum1[maxn], rsum2[maxn];
int main(int argc, char const *argv[])
{
    int n, q, x;
    while (cin >> n >> q) {
        memset(sum, 0, sizeof sum); memset(sum1, 0, sizeof sum1);
        memset(sum2, 0, sizeof sum2); memset(rsum, 0, sizeof rsum);
        memset(rsum1, 0, sizeof rsum1); memset(rsum2, 0, sizeof rsum2);
        for (int i = 1; i <= n; i++) {
            cin >> sum[i];
            sum1[i] = sum[i];
            sum2[i] = sum[i];
        }
        for (int i = 2; i <= n; i++) sum[i] = sum[i-1] & sum[i];
        for (int i = 2; i <= n; i++) sum1[i] = sum1[i-1] | sum1[i];
        for (int i = 2; i <= n; i++) sum2[i] = sum2[i-1] ^ sum2[i];
        for (int i = n; i >= 2; i++) rsum[i-1] = rsum[i-1] & rsum[i];
        for (int i = n; i >= 2; i++) rsum1[i-1] = rsum1[i-1] | rsum1[i];
        for (int i = n; i >= 2; i++) rsum2[i-1] = rsum2[i-1] ^ rsum2[i];
        while (q--) {
            cin >> x;
            if (x == 1) printf("%d %d %d\n", sum[2], sum[2], sum[2]);
            else if (x == n) printf("%d %d %d\n", sum[n-1], sum1[n-1], sum2[n-1]);
            else printf("%d %d %d\n", sum[x-1]&rsum[x+1] , sum1[x-1]|rsum1[x+1], sum2[x-1]^rsum2[x+1]);
        }
    }
    return 0;
}
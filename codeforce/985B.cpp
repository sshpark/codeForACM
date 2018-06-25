#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 2005;
char str[maxn];
int a[maxn][maxn], ans[maxn];
int main(int argc, char const *argv[])
{
    int n, m;
    memset(ans, 0, sizeof ans);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        for (int j = 0; j < m; j++)
            a[i][j] = str[j]-'0';
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j] += a[i][j];
        }
    }
    
    int sum;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < m; j++)
            sum += ans[j]-a[i][j] ? 1 : 0;

        if (sum == m) {
            flag = true;
            break;
        }
    }
    puts(flag ? "YES" : "NO");

    return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1005;
int a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    while(~scanf("%d", &n)) {
        int sum = 0;
        int maxa = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
            maxa = max(maxa, a[i]);
        }

        int ans = 10000000, res = 1, tmp;
        for (int t = 1; t <= maxa+1; t++) {
            tmp = 0;
            for (int i = 0; i < n; i++)
                if (abs(a[i]-t) > 1) 
                    tmp += abs(a[i]-t)-1;
            if (tmp < ans) {
                ans = tmp;
                res = t;
            }
        }
        printf("%d %d\n", res, ans);
        
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int len, n, x, a[1000000];
    memset(a, 0, sizeof a);
    a[1] = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
        len = sqrt(x);
        for (int j = 2; j <= len; j++) {
            if (x % j == 0) {
                a[j]++;
                if (j*j != x) a[x/j]++;
            }
        }
    }
    int maxa = -12;
    for (int i = 1; i < 1000000; i++)
        if (a[i] >= 2)
            maxa = max(maxa, i);
    printf("%d\n", maxa);
    return 0;
}
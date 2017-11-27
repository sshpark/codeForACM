#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, a[200005], ans = 0;
    memset(a, 0, sizeof a);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        if (a[k]) a[k]--,a[i]++;
        else ans++, a[i]++;
    }
    printf("%d\n", ans);

    return 0;
}
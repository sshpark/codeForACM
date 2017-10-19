#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, a[5005], b[5005];
    int op[5005], l[5005], r[5005], x[5005];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i] = 100000000;
        b[i] = 0;
    }
    for (int i = 0; i < m; i++)
        scanf("%d %d %d %d", op+i, l+i, r+i, x+i);
    for (int i = 0; i < m; i++)
        if (op[i] == 1)
            for (int k = l[i]; k <= r[i]; k++)
                b[k] += x[i];
        else
            for (int k = l[i]; k <= r[i]; k++)
                a[k] = min(a[k], x[i]-b[k]);
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 0; i < m; i++) {
        if (op[i] == 1)
            for (int j = l[i]; j <= r[i]; j++)
                b[j] += x[i];
        else {
            int mx = -100000000;
            for (int j = l[i]; j <= r[i]; j++)
                mx = max(mx, b[j]);
            if (mx != x[i]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int T, n, a[10], b[10];
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) scanf("%d", a+j);
        for (int j = 1; j <= n; j++) scanf("%d", b+j);
        int fz = b[n], fm = a[n];
        for (int i = n-1; i >= 1; i--) {
            fz += fm*a[i];
            fm *= b[i];
            swap(fz, fm);
        }
        int k = __gcd(fz, fm);
        printf("Case #%d: %d %d\n", i, fz/k, fm/k);
    }

    return 0;
}
#include <iostream>
#include <string.h>
#include <vector>
#define ull unsigned long long
using namespace std;
int qpow(ull a, ull b, int m) {
    a = a%m;
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1; 
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ull a, b;
    int n, T, loop[1005];
    vector<int> f[1005];
    for (int p = 2; p <= 1004; p++) {
        f[p].push_back(0);
        f[p].push_back(1);
        for (int i = 2; ; i++) {
            f[p].push_back((f[p][i-2] + f[p][i-1])%p);
            if (f[p][i] == 1 && f[p][i-1] == 0) {
                loop[p] = i-1;
                break;
            }
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%llu %llu %d", &a, &b, &n);
        if (a == 0 || n == 1) {
            puts("0");
            continue;
        }
        printf("%d\n", f[n][qpow(a, b, loop[n])]);
   }
    return 0;
}
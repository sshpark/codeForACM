#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, kase = 0;
    while (~scanf("%d", &n) && n) {
        int len = sqrt(n);
        int cnt = 0;
        long long sum = 0, t;
        for (int i = 2; i <= len; i++) {
            if (n % i == 0) {
                cnt++;
                t = 1;
                while (n % i == 0) {
                    t *= i;
                    n /= i;
                }
                sum += t;
            }
        }
        if (cnt == 0) sum = (long long)n+1;
        else if (cnt == 1 || n != 1) sum += n;
        printf("Case %d: %lld\n", ++kase, sum);
    }
    return 0;
}
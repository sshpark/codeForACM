#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int L, N, C, T;
    int vr, vt1, vt2;
    double a[105], dp[105];
    while (~scanf("%d", &L)) {
        scanf("%d %d %d", &N, &C, &T);
        scanf("%d %d %d", &vr, &vt1, &vt2);
        for (int i = 1; i <= N; i++) scanf("%lf", a+i);
        a[0] = dp[0] = 0, a[N+1] = L;
        for (int i = 1; i <= N+1; i++) {
            double mina = 100000000;
            for (int j = 0; j < i; j++) {
                double temp;
                if (a[i] - a[j] >= C)
                    temp = dp[j]+C*1.0/vt1+(a[i]-a[j]-C)*1.0/vt2;
                else
                    temp = dp[j]+(a[i]-a[j])*1.0/vt1;
                if (j > 0) temp += T;
                mina = min(temp, mina);
            }
            dp[i] = mina;
        }
        puts(dp[N+1] < L*1.0/vr ? "What a pity rabbit!" : "Good job,rabbit!");
    }
    return 0;
}
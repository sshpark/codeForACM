#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    int xx[105], yy[105];
    printf("%d\n", 11|3);
    scanf("%d %d", &n, &k);
    double sum = 0;
    for (int i = 0; i < n; i++) scanf("%d %d", xx+i, yy+i);
    for (int i = 1; i < n; i++)
        sum += sqrt((xx[i]-xx[i-1])*(xx[i]-xx[i-1])*1.0+(yy[i]-yy[i-1])*(yy[i]-yy[i-1])*1.0);
    printf("%.9lf\n", sum*k/50);
    return 0;
}
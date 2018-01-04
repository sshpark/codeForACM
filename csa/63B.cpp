#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    double s;
    int q, k;
    cin >> s >> q >> k;
    int a[50];
    for (int i = 0; i < q; i++) cin >> a[i];
    sort(a, a+q);
    for (int i = 0; i < q; i++) {
        s = max(s+k, s*(a[i]/100.0+1));
    }
    printf("%.11lf\n", s);
    return 0;
}
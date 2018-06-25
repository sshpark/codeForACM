#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[200005];
int main(int argc, char const *argv[])
{
    int n, maxa = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    int col = 0, flag_col = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) return 0*printf("NO\n");
        if (!flag_col && abs(a[i]-a[i-1]) > 1) {
            col = abs(a[i]-a[i-1]);
            flag_col = 1;
        }
        if (flag_col && abs(a[i]-a[i-1]) > 1) {
            if (abs(a[i]-a[i-1]) != col) return 0*printf("NO\n");
        }
    }
    printf("YES\n");
    if (col == 0) printf("%d %d\n", maxa, 1);
    else printf("%d %d\n", maxa/col+1, col);



    return 0;
}
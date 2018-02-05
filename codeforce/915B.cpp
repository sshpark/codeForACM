#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n) return 0*printf("%d\n", 0);
    if (l == 1) return 0*printf("%d\n", abs(pos-r)+1);
    if (r == n) return 0*printf("%d\n", abs(pos-l)+1);

    if (pos < l) return 0*printf("%d\n", r-l+2+l-pos);
    if (pos > r) return 0*printf("%d\n", r-l+2+pos-r);
    return 0*printf("%d\n", min(pos-l, r-pos)+r-l+2);
}
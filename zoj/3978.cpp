#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;
#define eps 1e-8
int main(int argc, char const *argv[])
{
    int T, n;
    map<string, int> A, B;
    A["UFS2.0"]=2; A["UFS2.1"]=3; A["eMMC5.1"]=5; A["LPDDR3"]=4; A["LPDDR4"]=6; A["Sparse"]=7; A["Normal"]=3;
    B["UFS2.0"]=3; B["UFS2.1"]=5; B["eMMC5.1"]=2; B["LPDDR3"]=7; B["LPDDR4"]=3; B["Sparse"]=4; B["Normal"]=6;
    string a, b, c;
    scanf("%d", &T);
    while (T--) {
        double ans1 = 0, ans2 = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            ans1 += log10(A[a]) + log10(A[b]) + log10(A[c]);
            ans2 += log10(B[a]) + log10(B[b]) + log10(B[c]);
        }
        if (abs(ans1-ans2) < eps) puts("E");
        else if (ans1 > ans2) puts("A");
        else puts("B");
    }
    return 0;
}
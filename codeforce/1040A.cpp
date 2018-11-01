#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, a, b, x[25];
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n/2; i++) {
        if (x[i] != x[n-i+1] && x[i] != 2 && x[n-i+1] != 2) {
            return 0*printf("-1\n");
        }
    }
    int e = min(a, b);
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (x[i] == 2 && x[n-i+1] == 2) sum += e*2;
        else if (x[i] == 2) {
            if (x[n-i+1] == 0) sum += a;
            else sum += b;
        } else if (x[n-i+1] == 2) {
            if (x[i] == 0) sum += a;
            else sum += b;
        }
    }
    if (n&1 && x[n/2+1] == 2) sum += e;
    printf("%d\n", sum);

    return 0;
}
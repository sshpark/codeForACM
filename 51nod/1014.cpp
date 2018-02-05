#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int A, P;
    bool flag = false;
    scanf("%d %d", &P, &A);
    for (ll i = 1; i <= P; i++) {
        if (i*i%P == A) {
            flag = true;
            printf("%lld ", i);
        }
    }
    if (!flag) puts("No Solution");
    return 0;
}
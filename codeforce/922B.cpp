#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
inline bool ok(int a, int b, int c) {
    if (a+b <= c || a+c <= b || b+c <= a) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    int n, a[5];
    int sum = 0, temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            a[0] = i, a[1] = j, a[2] = i^j;
            if (a[2] < 1 || a[2] > n) continue;
            sort(a, a+3);
            if (ok(a[0], a[1], a[2])) sum++;
        }
            
    printf("%d\n", sum/6);
    return 0;
}
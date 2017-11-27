#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;
#define ll long long
int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
int main(int argc, char const *argv[])
{
    int n, a[2005], ones = 0, ans = 100000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        if (a[i] == 1) ones++;
    }
    if (ones) {printf("%d\n", n-ones);return 0;}
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        for (int j = i; j < n; j++) {
            temp = gcd(temp, a[j]);
            if (temp == 1) {
                ans = min(ans, j-i+n-1);
                break;
            }
        }
    }
    printf("%d\n", ans == 100000000 ? -1 : ans);
    return 0;
}
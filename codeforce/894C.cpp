#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main(int argc, char const *argv[])
{
    int n, a[1005], sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    sum = a[1];
    for (int i = 2; i <= n; i++)
        sum = gcd(sum, a[i]);
    if (sum != a[1]) {
        puts("-1");
    } else {
        printf("%d\n", n<<1);
        for (int i = 1; i <= n; i++)
            printf("%d %d ", sum, a[i]);
    }
    return 0;
}
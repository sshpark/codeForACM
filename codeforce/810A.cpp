#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, x;
    scanf("%d %d", &n, &k);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        sum += x;
    }
    x = 0;
    while (round(sum*1.0/(n+x)) < k) {
        sum += k;
        x++;
    }
    printf("%d\n", x);
    return 0;
}
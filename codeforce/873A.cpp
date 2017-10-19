#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, x, q;
    int sum = 0;
    scanf("%d %d %d", &n, &k, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q);
        if (i <= n-k) sum += q;
        else sum += x;
    }
    printf("%d\n", sum);
    return 0;
}
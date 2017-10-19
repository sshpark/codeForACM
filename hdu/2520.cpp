#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", (n+n*(n-1))%10000);
    }
    return 0;
}
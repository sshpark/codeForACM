#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x, now = 0, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x - now > 0) {
            t = t + 6*(x-now) + 5;
        }
        else {
            t = t + 4*(now-x) + 5;
        }
        now = x;
    }
    printf("%d\n", t);
    return 0;
}
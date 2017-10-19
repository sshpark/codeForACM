#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 200005;
long long maxa[maxn];
int main(int argc, char const *argv[])
{
    int m, d, x, top = 0;
    char op[5];
    long long q = 0;
    scanf("%d %d", &m, &d);
    while (m--) {
        scanf("%s %d", op, &x);
        if (op[0] == 'A') {
            top++;
            long long in = (x+q)%d;
            for (int j = top-1; j >= 0; j--)
                if (maxa[j] < in) maxa[j] = in;
                else break;
        }
        else {
            printf("%lld\n", maxa[top-x]);
            q = maxa[top-x];
        }
    }
    return 0;
}
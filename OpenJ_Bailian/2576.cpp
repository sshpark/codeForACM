#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    int l = 0, r = 100000, tempL, tempR;
    srand(0);
    for (int t = 0; t < 10005; t++) {
        tempL = tempR = 0;
        random_shuffle(a, a+n);
        for (int i = 0; i < n/2; i++) tempL += a[i];
        for (int i = n/2; i < n; i++) tempR += a[i];
        if (abs(tempR-tempL) < abs(r-l)) {
            r = tempR;
            l = tempL;
        }
    }
    printf("%d %d\n", min(l, r), max(l, r));
    return 0;
}
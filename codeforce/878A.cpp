#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{   
    int n, s[1005], d[1005];
    int ld;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &s[i], &d[i]);
    ld = s[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; ; j++)
            if (s[i]+j*d[i] > ld) {
                ld = s[i]+j*d[i];
                break;
            }
    }
    printf("%d\n", ld);
    return 0;
}
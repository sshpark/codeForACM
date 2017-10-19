#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T, n;
    scanf("%d", &T);        
    while (T--) {
        scanf("%d", &n);
        int inc = n-1, la = 1;
        printf("1");
        for (int i = 2; i <= n; i++) {
            printf(" %d", la+(int)pow(-1, i)*inc);
            la = la+(int)pow(-1, i)*inc;
            inc--;
        }
        printf("\n");
    }
    return 0;
}
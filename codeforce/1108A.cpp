#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int q, l, r, l1, r1;
    scanf("%d", &q);

    while (q--) {
        scanf("%d %d %d %d", &l, &r, &l1, &r1);
        if (l != r1) {
            printf("%d %d\n", l, r1);
        } else {
            printf("%d %d\n", r, l1);
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;
#define ll long long
const int maxn = 100005;
int h[maxn];
int main(int argc, char const *argv[])
{
    int n, flag = 0, spj = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++)
        if (h[i] > 1 && h[i-1] > 1) spj = 1;
    if (!spj) {
        printf("perfect\n");
        return 0;
    } else {
        int sum = 0;
        printf("ambiguous\n");
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                printf("0 ");
                sum++;
            } else {
                for (int j = 1; j <= h[i]; j++)
                    printf("%d ", sum);
                sum += h[i];
            }
        }
        printf("\n");
        sum = 0;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                printf("0 ");
                sum++;
            } else {
                if (h[i] != 1 && h[i-1] != 1) {
                    for (int j = 1; j < h[i]; j++) printf("%d ", sum);
                    printf("%d ", sum-1);
                } else {
                    for (int j = 1; j <= h[i]; j++) printf("%d ", sum);
                }
                sum += h[i];
            }
        }
        printf("\n");
    }
    return 0;
}
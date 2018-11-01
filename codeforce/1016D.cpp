#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, m;
    int r, c;
    int a[105], b[105];

    cin >> n >> m;

    r = c = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r ^= a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        c ^= b[i];
    }
    if (r != c) {
        puts("NO");
    } else {
        bool first;
        puts("YES");
        for (int i = 0; i < n; i++) {
            first = true;
            for (int j = 0; j < m; j++) {
                if (!first) printf(" ");
                else first = false;
                if (i != n-1 && j != m-1) {
                    printf("0");
                } else if (j == m-1 && i == n-1) {
                    r = 0;
                    for (int k = 0; k < m-1; k++) r ^= b[k];
                    r ^= a[n-1];
                    printf("%d", r);
                } else if (j == m-1){
                    printf("%d", a[i]);
                } else {
                    printf("%d", b[j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
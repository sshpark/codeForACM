#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
char str[2005][2005];
int n, m, k;

inline int ok(int s, int flag) {
    int sum = 0, cnt = 0;
    if (flag) {
        for (int i = 0; i < m; i++) {
            if (str[s][i] == '.') {
                cnt++;
                if (cnt >= k) sum++;
            } else cnt = 0;
        }
        return sum;
    } else {
        for (int i = 0; i < n; i++) {
            if (str[i][s] == '.') {
                cnt++;
                if (cnt >= k) sum++;
            } else cnt = 0;
        }
        return sum;
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        scanf("%s", str[i]);
    int sum = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (str[i][j] == '.') sum++;
        printf("%d\n", sum);
    } else {
        for (int i = 0; i < n; i++)
            sum += ok(i, 1);

        for (int i = 0; i < m; i++)
            sum += ok(i, 0);
        printf("%d\n", sum);
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1005;
int a[maxn], b[maxn];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int sum = 0, cnt = 0, flag = 0;
    for (int i = 0; i <= m-n; i++) {
        flag = cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j]+b[i+cnt] == 1) cnt++;
            else {
                flag = 1;
                break;
            }
        }
        if (!flag) sum++;
    }
    printf("%d\n", sum);

    return 0;
}
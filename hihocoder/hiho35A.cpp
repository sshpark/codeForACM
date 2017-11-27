#include <stdio.h>
#include <iostream>
using namespace std;
int bit[10] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};
int temp[10];
int n;
inline bool ok(int x) {
    int q = x, cnt = 0;
    while (q) {
        temp[cnt++] = q%10;
        q /= 10;
    }
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (bit[temp[i]] == -1) return false;
        ans = ans*10 + bit[temp[i]];
    }
    int xcnt = 0, temp_ans = ans;
    while (ans) ans/=10, xcnt++;
    if (xcnt < cnt) return false;
    return temp_ans <= n && temp_ans != x;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        if (ok(i)) printf("%d\n", i);
    return 0;
}
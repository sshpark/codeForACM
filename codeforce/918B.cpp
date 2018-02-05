#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
char str[5005];
int main(int argc, char const *argv[])
{
    scanf("%s", str+1);
    int n = strlen(str+1);
    int l, r, ans = 0;
    for (int i = 1; i <= n; i++) {
        l = r = 0;
        for (int j = i; j <= n; j++) {
            if (str[j] == '(') l++, r++;
            else if (str[j] == ')') l--, r--;
            else l--, r++; // 问号，)则l--, (则r++
            if (l < 0) l += 2;
            if (r < 0) break;
            if (l == 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
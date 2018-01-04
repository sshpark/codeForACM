#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
inline bool ok(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    if (c <= '9' && c >= '0' && (c-'0')%2 != 0) return true;
    return false;
}
int main(int argc, char const *argv[])
{
    char str[55];
    int cnt = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (ok(str[i])) cnt++;
    printf("%d\n", cnt);
    return 0;
}
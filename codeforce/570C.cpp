#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[300005];
int main(int argc, char const *argv[])
{
    int n, k, p, ans = 0;
    char op[5];
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 1; i < n; i++)
        if (str[i] == '.' && str[i-1] == '.') ans++;
    while (k--) {
        scanf("%d %s", &p, op);
        if ((op[0] == '.' && str[p-1] == '.')||(str[p-1] != '.' && op[0] != '.'));
        else {
            if (op[0] == '.') {
                if (p != 1 && str[p-2] == '.') ans++;
                if (p != n && str[p] == '.') ans++;
            }
            else {
                if (p != 1 && str[p-2] == '.') ans--;
                if (p != n && str[p] =='.') ans--;
            }
        }
        str[p-1] = op[0];
        printf("%d\n", ans);
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, line = 0, zero = 0;
    char str[105];
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '-') {
            line++;
        } else {
            zero++;
        }
    }
    if (line == 0 || zero == 0) {
        printf("YES\n");
    } else if (zero > line) {
        printf("NO\n");
    } else {
        if (line % zero == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
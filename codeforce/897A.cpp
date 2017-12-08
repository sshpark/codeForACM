#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, a, b;
    char c, d;
    char str[105];
    cin >> n >> m;
    scanf("%s", str);
    while (m--) {
        scanf("%d %d %c %c", &a, &b, &c, &d);
        for (int i = a-1; i <= b-1; i++)
            if (str[i] == c) str[i] = d;
    }
    printf("%s\n", str);
    return 0;
}
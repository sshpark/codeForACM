#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
char str[200005];
vector<int> p[200005];
int main(int argc, char const *argv[])
{
    scanf("%s", str);
    int n = strlen(str);
    int flag = 1;
    int maxa = 0, zero = 0;
    for (int i = 0; i < n && flag; i++) {
        if (str[i] == '0') {
            p[++zero].push_back(i+1);
        } else {
            if (zero == 0) flag = 0;
            p[zero--].push_back(i+1);
        }
        maxa = max(maxa, zero);
    }
    if (maxa != zero) flag = 0;
    if (flag == 0) {
        puts("-1");
    } else {
        printf("%d\n", maxa);
        for (int i = 1; i <= maxa; i++) {
            printf("%d", (int)p[i].size());
            for (auto j : p[i]) printf(" %d", j);
            printf("\n");
        }
    }

    return 0;
}
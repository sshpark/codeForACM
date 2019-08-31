#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/codeforce/1.in", "r", stdin);
    char str[105];
    while(~scanf("%s", str)) {
        int n = strlen(str);
        int a = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '1') a++;
        
        int ans = (n-1)/2+1;
        if (a <= 1 && (n-1)%2 == 0) ans--;

        printf("%d\n", ans);
    }
    return 0;
}
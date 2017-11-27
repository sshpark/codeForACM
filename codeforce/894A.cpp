#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    char str[105];
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    for (int i = 0; i < len; i++)
        for (int j = i+1; j < len; j++)
            for (int k = j+1; k < len; k++)
                if (str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q') ans++;
    printf("%d\n", ans);
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 1000005;
char str[maxn<<1], read_str[maxn];
int RL[maxn<<1];
void init() {
    int len = strlen(read_str);
    for (int i = 0; i < len; i++) {
        str[i<<1] = '#';
        str[i<<1|1] = read_str[i];
    }
    str[len<<1] = '#';
}
int manacher(int n) {
    memset(RL, 0, sizeof RL);
    int MaxRight = 0, pos = 0, MaxLen = 0;
    for (int i = 0; i < n; i++) {
        if (i < MaxRight) RL[i] = min(RL[2*pos-i], MaxRight-i);
        else RL[i] = 0;
        while (i-RL[i] >= 0 and i+RL[i] < n and str[i-RL[i]] == str[i+RL[i]]) RL[i]++;
        if (RL[i]+i-1 > MaxRight) {
            MaxRight = RL[i]+i-1;
            pos = i;
        }
        MaxLen = max(MaxLen, RL[i]);
    }
    return MaxLen;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", read_str);
        init();
        printf("%d\n", manacher(strlen(read_str)<<1|1)-1);
    }
    return 0;
}
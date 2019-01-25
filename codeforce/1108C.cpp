#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
char str[maxn];
char res[6][maxn];

int main(int argc, char const *argv[])
{
    int n, pos = 0;
    int mina = 1000000000;

    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < 6; i++) strcpy(res[i], str);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'R') cnt++, res[0][i] = 'R';
        if (i%3 == 1 && str[i] != 'G') cnt++, res[0][i] = 'G';
        if (i%3 == 2 && str[i] != 'B') cnt++, res[0][i] = 'B';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 0;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'R') cnt++, res[1][i] = 'R';
        if (i%3 == 1 && str[i] != 'B') cnt++, res[1][i] = 'B';
        if (i%3 == 2 && str[i] != 'G') cnt++, res[1][i] = 'G';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 1;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'G') cnt++, res[2][i] = 'G';
        if (i%3 == 1 && str[i] != 'R') cnt++, res[2][i] = 'R';
        if (i%3 == 2 && str[i] != 'B') cnt++, res[2][i] = 'B';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 2;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'G') cnt++, res[3][i] = 'G';
        if (i%3 == 1 && str[i] != 'B') cnt++, res[3][i] = 'B';
        if (i%3 == 2 && str[i] != 'R') cnt++, res[3][i] = 'R';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 3;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'B') cnt++, res[4][i] = 'B';
        if (i%3 == 1 && str[i] != 'G') cnt++, res[4][i] = 'G';
        if (i%3 == 2 && str[i] != 'R') cnt++, res[4][i] = 'R';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 4;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 0 && str[i] != 'B') cnt++, res[5][i] = 'B';
        if (i%3 == 1 && str[i] != 'R') cnt++, res[5][i] = 'R';
        if (i%3 == 2 && str[i] != 'G') cnt++, res[5][i] = 'G';
    }
    if (cnt < mina) {
        mina = cnt;
        pos = 5;
    }
    res[pos][n] = '\0';
    printf("%d\n", mina);
    puts(res[pos]);

    return 0;
}
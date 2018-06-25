#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
char ku[maxn], sh[maxn], ka[maxn];
int nn[3][105], maxa[3];
int main(int argc, char const *argv[])
{
    memset(nn, 0, sizeof nn);
    int n;
    scanf("%d", &n);
    scanf("%s", ku);
    scanf("%s", sh);
    scanf("%s", ka);

    int len = strlen(ku);

    for (int i = 0; i < len; i++) {
        nn[0][ku[i]-'A']++;
        nn[1][sh[i]-'A']++;
        nn[2][ka[i]-'A']++;
    }
    maxa[0] = maxa[1] = maxa[2] = 0;
    for (int i = 0; i < 105; i++) {
        maxa[0] = max(maxa[0], nn[0][i]);
        maxa[1] = max(maxa[1], nn[1][i]);
        maxa[2] = max(maxa[2], nn[2][i]);
    }

    if (n+maxa[0] <= len) maxa[0] = n+maxa[0];
    else { 
        int temp = n-maxa[0];
        maxa[0] = max(temp%len==0?len:temp%len, len-(temp%len)==len?0:len-(temp%len));
    }
    if (n+maxa[1] <= len) maxa[1] = n+maxa[1];
    else { 
        int temp = n-maxa[1];
        maxa[1] = max(temp%len==1?len:temp%len, len-(temp%len)==len?1:len-(temp%len));
    }
    if (n+maxa[2] <= len) maxa[2] = n+maxa[2];
    else { 
        int temp = n-maxa[2];
        maxa[2] = max(temp%len==2?len:temp%len, len-(temp%len)==len?2:len-(temp%len));
    }
    if (maxa[0] > maxa[1] && maxa[0] > maxa[2]) {
        puts("Kuro");
    } else if (maxa[1] > maxa[0] && maxa[1] > maxa[2]) {
        puts("Shiro");
    } else if (maxa[2] > maxa[0] && maxa[2] > maxa[1]) {
        puts("Katie");
    } else {
        puts("Draw");
    }



    return 0;
}
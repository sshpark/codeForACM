#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int n;
int a[15], b[15], cnt, num;
int main(int argc, char const *argv[])
{
    cin >> n;
    int mina = 15;
    cnt = 0;
    int temp = n;
    while (temp) {
        a[cnt++] = temp%10;
        temp /= 10;
    }

    for (int i = 1; i*i <= n; i++) {
        num = 0;
        temp = i*i;
        while (temp) {
            b[num++] = temp%10;
            temp /= 10;
        }
        int k = 0;
        for (int j = 0; j < cnt; j++) {
            if (a[j] == b[k]) {
                k++;
            }
            if (k == num) break;
        }
        if (k == num) mina = min(mina, cnt-k);
    }
    printf("%d\n", mina == 15 ? -1 : mina);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int k;
    char str[25];
    cin >> k;
    if (k <= 36) {
        int cnt = 0, x = 0;
        while (true) {
            if (x+2 <= k) {
                str[cnt++] = '8';
                x+=2;
                if (x == k) {
                    str[cnt++] = '\0';
                    break;
                }
            } else {
                str[cnt++] = '4';
                str[cnt++] = '\0';
                break;
            }
        }
        printf("%s\n", str);
    } else puts("-1");
    return 0;
}
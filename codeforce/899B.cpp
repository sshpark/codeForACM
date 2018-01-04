#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int n, x, a[60];
int mon[60] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool ok(int len) {
    int j, cnt = 0;
    for (int i = 1; i <= 48-len+1; i++) {
        int st = i;
        for (j = 0; j < len; j++) {
            if (a[j] == mon[st] || (a[j] == 29 && mon[st] == 28)) {
                if (a[j] == 29) cnt++;
                ++st;
            }
            else break; 
        }
        if (cnt > 1) return false;
        if (j == len) return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
        if (ok(n)) {
            return 0*printf("YES\n");
        }
    printf("NO\n");

    return 0;
}
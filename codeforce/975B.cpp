#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll a[15], b[15];
int main(int argc, char const *argv[])
{
    ll temp;
    int st, lop;

    for (int i = 0; i < 14; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    ll maxa = 0, cnt;
    for (int i = 0; i < 14; i++) {
        if (a[i]) {
            b[i] = 0;
            temp = a[i]/14;
            lop = a[i]%14;
            st = (i+1)%14;
            for (int j = 0; j < 14; j++) b[j] += temp;
            for (int j = 0; j < lop; j++) {
                b[st]++;
                st = (st+1)%14;
            }
            cnt = 0;
            for (int j = 0; j < 14; j++)
                if (b[j]%2 == 0) cnt += b[j];
            maxa = max(maxa, cnt);
            for (int j = 0; j < 14; j++) b[j] = a[j];
        }
    }
    printf("%lld\n", maxa);
    return 0;
}
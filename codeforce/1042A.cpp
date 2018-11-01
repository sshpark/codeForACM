#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, m, x, sum = 0, maxa = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        maxa = max(maxa, x);
        sum += x;
    }
    sort(a, a+n);
    int temp = m, cnt = 0;
    while (temp) {
        if (cnt < n) {
            temp -= a[cnt+1]-a[cnt];
            a[cnt] = a[cnt+1];
        }
        cnt++;
    }


    return 0;
}
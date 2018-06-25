#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[105];
int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    int n = x/2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int st = 1, sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(st-a[i]);
        st += 2;
    }
    st = 2;
    for (int i = 0; i < n; i++) {
        sum1 += abs(st-a[i]);
        st += 2;
    }
    printf("%d\n", min(sum, sum1));
    return 0;
}
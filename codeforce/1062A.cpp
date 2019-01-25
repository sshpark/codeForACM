#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[105];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    int maxa = 0, cur = 1;
    for (int i = 1; i < n; i++) {
        if (a[i]-1 == a[i-1]) {
            cur++;
        } else {
            maxa = max(maxa, cur);
            cur = 1;
        }
    }
    maxa = max(maxa, cur);
    if (maxa == 2 && n == 2) printf("0\n");
    else {
        if (maxa == n) maxa--;
        else maxa -= 2;
        printf("%d\n", max(maxa, 0));
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, a, b;
    int maxa = -1;
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++)
        maxa = max(maxa, min(a/i, b/(n-i)));
    printf("%d\n", maxa);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, k, x;
    int mina = 10000000;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (k % x == 0)
            mina = min(k/x, mina);
    }
    printf("%d\n", mina);
    return 0;
}
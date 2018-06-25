#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int a, b, sum = 0, i = 1, j = 1;
    cin >> a >> b;
    if (a > b) swap(a, b);

    while (a != b) {
        a++;
        sum += i++;
        if (a == b) break;
        b--;
        sum += j++;
    }
    printf("%d\n", sum);
    return 0;
}
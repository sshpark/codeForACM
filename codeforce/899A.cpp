#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, x, a, b;
    cin >> n;
    a = b = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) a++;
        else b++;
    }
    if (b > a)
        printf("%d\n", a+(b-a)/6*2);
    else if (b < a) {
        printf("%d\n", b+(a-b)/3);
    }
    return 0;
}
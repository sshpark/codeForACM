#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int x, y;
    while (cin >> x >> y) {
    if (y == 0) {printf("No\n"); continue;}
    if (y == 1 && x > 0) {printf("No\n"); continue;}
    if (x-y+1 >= 0) puts((x-y+1)%2 == 0 ? "Yes" : "No");
    else puts("No");
    }
    return 0;
}
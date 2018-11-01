#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int temp = n-2;
    int cnt = 0;
    while (temp%3 == 0) {
        cnt++;
        temp--;
    }
    printf("1 %d %d\n", 1+cnt, n-2-cnt);
    return 0;
}
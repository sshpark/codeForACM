#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[1005];
int main(int argc, char const *argv[])
{    
    int n;
    int x, y, z;
    x = y = z = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) x++;
        else if (a[i] == 1) y++;
        else z++;
    }
    int sum = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) sum += 2;
        if (a[i] == 2) sum += 1;
    }
        
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) sum1 += 1;
        if (a[i] == 2) sum1 += 2;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) sum2 += 2;
        if (a[i] == 1) sum2 += 1;
    }
    printf("%d\n", min(sum, min(sum1, sum2)));
    return 0;
}
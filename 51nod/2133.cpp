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
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]*(n-i);
    }
    printf("%d\n", sum);
    return 0;
}
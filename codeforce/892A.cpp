#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n, sum = 0, ans[100005], x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    sort(ans, ans+n);
    if (sum <= ans[n-1]+ans[n-2])
        puts("YES");
    else
        puts("NO");
    return 0;
}
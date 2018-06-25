#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int a[maxn], id[maxn];
int main(int argc, char const *argv[])
{
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            id[a[i]] = i;
        }
        for (int i = 0; i < n && k > 0; i++) {
            if (a[i] == n-i) continue;
            a[id[n - i]] = a[i];
            id[a[i]] = id[n - i];
            a[i] = n - i;
            id[n - i] = i;        
            k--;
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], " \n"[i == n-1]);
    }
    return 0;
}
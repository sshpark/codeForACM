#include <iostream>
#include <algorithm>
#include <set>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, a[15];
    set<int> s;
    cin >> n;   
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                s.insert(a[i]+a[j]);
    printf("%d\n", (int)s.size());

    return 0;
}
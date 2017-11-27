#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[200005];
    set<int> s, s1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        s.insert(a[i]);
    }
    int m = (int)s.size();
    for (int i = n-1; i >= 0; i--) {
        s1.insert(a[i]);
        if ((int)s1.size() == m) {
            printf("%d\n", a[i]);
            return 0;
        }
    }
    return 0;
}
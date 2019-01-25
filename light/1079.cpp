#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int T;
    int n, m, x;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &m);
        puts(n <= m ? "Yes" : "No");
        for (int i = 0; i < n+m; i++)
            scanf("%d", &x);
    }
    
    return 0;
}
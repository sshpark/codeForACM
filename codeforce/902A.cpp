#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int e[105][105];
int main(int argc, char const *argv[])
{
    int n, m, flag = 1, a, b;
    memset(e, 0, sizeof e);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++)
            e[j][j+1] = 1;
    }
    for (int i = 0; i < m; i++)
        if (e[i][i+1] == 0) return 0*printf("NO\n");
    printf("YES\n");
    return 0;
    
}
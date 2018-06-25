#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int ans[15];
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int temp = a*10;
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < b-1; i++) {
        ans[temp/b] = 1;
        temp = temp%b*10;
    }
    for (int i = 0; i < 10; i++)
        if (ans[i]) printf("%d", i);
    printf("\n");
    return 0;
}
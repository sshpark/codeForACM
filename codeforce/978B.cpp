#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n;
    char str[105];
    cin >> n;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < n-2; i++) {
        if (str[i] == 'x' && str[i+1] == 'x' && str[i+2] == 'x') sum++;
    }
    printf("%d\n", sum);
    return 0;
}
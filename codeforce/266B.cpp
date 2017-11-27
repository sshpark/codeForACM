#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, t;
    char str[55], temp[55];
    scanf("%d %d", &n, &t);
    scanf("%s", str);
    strcpy(temp, str);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n-1; j++)
            if (temp[j] == 'B' && temp[j+1] == 'G') {
                swap(str[j], str[j+1]);
            }
        strcpy(temp, str);
    }
    printf("%s\n", str);
    return 0;
}
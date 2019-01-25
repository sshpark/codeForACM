#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
char str[maxn];
void changeR(char a, int x) {
    if (a == 'G' || a == 'R') {
        str[x] = 'B';
    } else {
        str[x] = 'G';
    }
}
void changeB(char a, int x) {
    if (a == 'B' || a == 'R') {
        str[x] = 'G'; 
    } else {
        str[x] = 'R';
    }
}
void changeG(char a, int x) {
    if (a == 'G' || a == 'R') {
        str[x] = 'B'; 
    } else {
        str[x] = 'R';
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int cnt = 0;
    for (int i = 1; i < n-1; i++) {
        if (str[i] == str[i-1]) {
            cnt++;
            if (str[i] == 'R') changeR(str[i+1], i);
            else if (str[i] == 'G') changeG(str[i+1], i);
            else changeB(str[i+1], i);
        }
    }
    if (str[n-1] == str[n-2]) {
        cnt++;
        if (str[n-1] == 'R') str[n-1] = 'B';
        else if (str[n-1] == 'G') str[n-1] = 'B';
        else str[n-1] = 'R';
    }
    printf("%d\n", cnt);
    puts(str);
    return 0;
}

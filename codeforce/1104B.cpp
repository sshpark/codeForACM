#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
char str[maxn];
char stk[maxn];
int top = 0;
int main(int argc, char const *argv[])
{
    scanf("%s", str);

    int n = strlen(str);
    int cur = 0;

    for (int i = 0; i < n; i++) {
        if (top == 0) {
            stk[++top] = str[i];
        } else {
            int cnt = top;
            while (str[i] == stk[cnt]) --cnt;
            if (cnt != top) {
                cur = !cur;
                top = cnt;
            }
            else stk[++top] = str[i];
        }
    }
    puts(cur ? "Yes" : "No");
    

    return 0;
}
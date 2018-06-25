#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
using namespace std;
#define ll long long
const int maxn = 100005;
char str[maxn];
set<char> s;
int a[30];
int main(int argc, char const *argv[])
{
    memset(a, 0, sizeof a);
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        a[str[i]-'a']++;
        s.insert(str[i]);
    }
    if (s.size() == 2) {
        if (n < 4) {
            puts("No");
        } else {
            int flag = 0;
            for (int i = 0; i < 30; i++)
                if (a[i] > 0 && a[i] < 2) {
                    flag = 1;
                    break;
                }
            if (flag) puts("No");
            else puts("Yes");
        }
    } else if (s.size() == 3) {
        puts(n >= 4 ? "Yes" : "No");
    } else if (s.size() == 4) {
        puts("Yes");
    } else {
        puts("No");
    }


    return 0;
}
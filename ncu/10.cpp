#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
#define rep(i, k, n) for (int i = k; i < n; i++)
#define repp(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
map<char, int> mm;
inline int getVal(char c) {
    if (c <= '9' && c >= '0') return c-'0';
    return mm[c];
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    mm['A'] = 10;mm['B'] = 11;mm['C'] = 12;mm['D'] = 13;mm['E'] = 14;mm['F'] = 15;
    char str[10];
    scanf("%s", str);
    if (str[0] == '0' && str[1] == '0' && str[2] == '0') {
        puts("0 0 0");
        return 0;
    }
    int sum = 16*16*getVal(str[0])+16*getVal(str[1])+getVal(str[2]);
    printf("%s %d ", str, sum);
    int ans[10], cnt = 0;
    while (sum) {
        ans[cnt++] = sum%8;
        sum /= 8;
    }
    for (int i = cnt-1; i >= 0; i--) printf("%d", ans[i]);
    printf("\n");


    return 0;
}
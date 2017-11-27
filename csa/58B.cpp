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
const int inf = 0x3f3f3f3f;
struct node {
    int l, r;
}p[2005];
bool cmp(node a, node b) {
    return a.l < b.l;
}

int main(int argc, char * argv[]) 
{
    int n, d = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &p[i].l, &p[i].r);
    sort(p+1, p+n+1, cmp);
    ll ans = 0, temp = 0, mina = 100000000000000;
    for (int i = 1; i <= n; i++) {
        temp = 0;
        for (int j = i; j >= 2; j--) {
            temp += p[j].l - p[j-1].r;
            ans += temp;
        }
        temp = 0;
        for (int j = i; j < n; j++) {
            temp += p[j+1].l - p[j].r;
            ans += temp;
        }
        mina = min(mina, ans);
        ans = 0;
    }
    printf("%lld\n", mina);
    return 0;
}
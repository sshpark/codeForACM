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

struct pt {
    int x, y;
    int id;
    int dis;
}p[105];

bool cmp(pt a, pt b) {
    return a.dis < b.dis;
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int T;
    int n, R, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &R, &r);
        rep(i, 0, n) {
            scanf("%d %d", &p[i].x, &p[i].y);
            p[i].id = i+1;
            p[i].dis = p[i].x*p[i].x + p[i].y*p[i].y;
        }
        int flag = 0;
        vector<int> v;
        rep(i, 0, n)
            if (p[i].dis <= (R-r*2)*(R-r*2)) {
                flag = 1;
                v.push_back(p[i].id);
            }
        
        if (!flag) {
            sort(p, p+n, cmp);
            v.push_back(p[0].id);
            rep(i, 1, n)
                if (p[i].dis == p[i-1].dis)
                    v.push_back(p[i].id);
        }
        printf("%d\n", (int)v.size());
        sort(v.begin(), v.end());
        printf("%d", v[0]);
        rep(i, 1, (int)v.size()) printf(" %d", v[i]);
        printf("\n");
    }

    return 0;
}
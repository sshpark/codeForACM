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
int n, a[20], cnt = 0, temp, flag = 0;

void getBin(int temp) {
    while (temp) {
        a[++cnt] = temp%2;
        temp >>= 1;
    }    
}

bool ok() {
    if (cnt % 2 == 0) return false;
    int sum = 0;
    for (int i = 1; i <= cnt; i++) {
        if (a[i]==0) sum++;
        if (a[i] != 0) break;
        if (sum > cnt/2) return false;
    }
    if (sum != cnt/2) return false;
    sum = 0;
    for (int i = cnt/2+1; i <= cnt; i++) {
        if (a[i] != 1) return false;
    }

    return true;
}

inline int getVal() {
    int sum = 0;
    for (int i = 1; i <= cnt; i++)
        sum += pow(2, i-1)*a[i];
    return sum;
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = n; i >= 1; i--) {
        if (n%i==0) {
            getBin(i);
            if (ok()) {
                printf("%d\n", getVal());
                return 0;
            }
            cnt = 0;
        }
    }
    
    return 0;
}
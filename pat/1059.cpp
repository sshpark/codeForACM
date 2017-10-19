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

bool isp[10005];
void shai() {
    memset(isp, true, sizeof isp);
    for (int i = 2; i < 10005; i++)
        if (isp[i])
            for (int j = i*i; j < 10005; j+=i)
                isp[j] = false;
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    map<string, int> m;
    set<string> has;
    int n, k;
    string s;
    cin >> n;
    shai();
    repp(i, 1, n){
        cin >> s;
        m[s] = i;
    } 
    cin >> k;
    rep(i, 0, k) {
        cin >> s;
        if (m[s] == 0) cout << s << ": Are you kidding?\n";
        else {
            if (has.find(s) != has.end()) {
                cout << s << ": Checked\n";
                continue;
            }
            if (m[s] == 1) cout << s << ": Mystery Award\n";
            else if (isp[m[s]]) cout << s << ": Minion\n";
            else cout << s << ": Chocolate\n";
            has.insert(s);
        }
    }
    return 0;
}
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
// #define LOCAL
const int maxn = 1e7+10;
bool isp[maxn];
int p[maxn], cnt;
ll phi[maxn];
void phi_table (int n){
    for (int i=2;i<=n;i++) phi[i]=0;
    phi[1]=1;
    for (int i=2;i<=n;i++) if (!phi[i]) {
        for (int j=i;j<=n;j+=i) {
            if (!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    }
}

void shuai(int n)
{
	memset(isp, true, sizeof(isp));
	for (ll i = 2; i <= n; i++)
	if (isp[i])
	{
		p[cnt++] = i;
		for (ll j = i*i; j <= n; j+=i)
			isp[j] = false;
	}
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	while (~scanf("%d", &n))
	{
		ll sum = 0;
		cnt = 0;
		phi_table(n);
		shuai(n);
		repp(i, 2, n) phi[i] += phi[i-1];
		rep(i, 0, cnt) sum += 2*phi[n/p[i]]-1;
		printf("%lld\n", sum);

	}

    return 0;
}
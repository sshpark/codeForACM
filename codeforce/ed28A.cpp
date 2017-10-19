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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
int main(){
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	int n;
	int a[105], vis[105];
	memset(vis, 0, sizeof vis);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	int ans=0;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		if(a[i]==1){
			if(a[i+1]==0&&(i+1<=n)) vis[i+1]=vis[i]=1, ans+=2;
			else continue;
		}else{
			int j=i-1;
			while(vis[j]&&j) j--;
			if(!j) continue;
			if(a[j]==1){
				vis[j]=vis[i]=1;
				ans+=2;
			}
		}
	}
	printf("%d\n", n-ans/2);
	return 0;
}
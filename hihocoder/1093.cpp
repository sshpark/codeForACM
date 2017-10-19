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
const int pmax = 100005;
const int eman = 1000005;
struct node {
	int to;
	int w;
	int next;
}edge[eman];
int pre[pmax], vis[pmax], dis[pmax], price[pmax];
int n, m, s, t;
queue<int> q;
void init() {
	int x, y, w;
	int id = 0;
	repp(i, 1, n) scanf("%d", price+i);
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[id].to = y;
		edge[id].w = w;
		edge[id].next = pre[x];
		pre[x] = id++;
		swap(x, y);
		edge[id].to = y;
		edge[id].w = w;
		edge[id].next = pre[x];
		pre[x] = id++;
	}

}
void spfa() {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x37, sizeof dis);
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].to;
			if (dis[e] > dis[top] + edge[i].w) {
				dis[e] = dis[top] + edge[i].w;
				if (!vis[e]) {
					q.push(e);
					vis[e] = 1;
				}
			}
		}
	}
	printf("%d\n", dis[t]);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		m = n-1;
		init();
		spfa();
		sort(dis+1, dis+n+1);
		printf("%d\n", );
	}
	
	return 0;
}
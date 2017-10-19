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
const int maxn = 100005;
int n, id, pre[maxn*2], vis[maxn*2], dis[maxn*2];

struct node {
	int to;
	int w;
	int next;
}edge[maxn*5];
void add(int x, int y, int w) {
	edge[id].to = y;
	edge[id].w = w;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void spfa() {
	queue<int> q;
	memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
	q.push(0);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].to;
			if (dis[e] > edge[i].w + dis[top]) {
				dis[e] = edge[i].w + dis[top];
				if (!vis[e]) {
					q.push(e);
					vis[e] = 1;
				}
			}
		}
	}
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, x, y, w;
	scanf("%d", &T);
	while (T--) {
		id = 0;
		memset(pre, -1, sizeof pre);
		scanf("%d", &n);
		repp(i, 1, n) {
			scanf("%d", &x);
			add(0, i, x);
			add(i, n+1, -x);
		}
		rep(i, 1, n) {
			scanf("%d %d %d", &x, &y, &w);
			add(x, y, -w);
			add(y, x, -w);
		}
		spfa();
		printf("%d\n", dis[n+1]);
	}

	return 0;
}
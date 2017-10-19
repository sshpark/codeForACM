#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 0xffffff;
const int pmax = 1010;
const int emax = 100010;
int id, id1, pre[pmax], pre1[pmax], dis[pmax];
int n, m;
int s, t, k;
struct node {
	int to;
	int w;
	int next;
}edge[emax], edge1[emax];
struct node1 {
	int to;
	int g;
	int f;
	bool operator < (const node1 &r) const {
		if (r.f == f) return r.g < g;
		return r.f < f;
	}
};
void add(int x, int y, int w) {
	edge[id].to = y;
	edge[id].w = w;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void add1(int x, int y, int w) {
	edge1[id1].to = y;
	edge1[id1].w = w;
	edge1[id1].next = pre1[x];
	pre1[x] = id1++;
}
bool spfa(int s,int n,int pre[], node edge[],int dis[]) {
	int vis[pmax];
	queue<int> q;
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		dis[i] = inf;
	}
	dis[s] = 0;
	q.push(s);
	vis[s]++;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top]--;
		if (vis[top] > n) return false;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			if (dis[edge[i].to] > dis[top] + edge[i].w) {
				dis[edge[i].to] = dis[top] + edge[i].w;
				if (!vis[edge[i].to]) {
					vis[edge[i].to]++;
					q.push(edge[i].to);
				}
			}
		}
	}
	return true;
}
int A_star(int s,int t,int n,int k,int pre[],node edge[],int dis[]) {
	node1 e, ne;
	int cnt = 0;
	if (s == t) k++;
	priority_queue<node1> que;
	if (dis[s] == inf)
		return -1;
	e.to = s;
	e.g = 0;
	e.f = e.g + dis[e.to];
	que.push(e);
	while (!que.empty()) {
		e = que.top();
		que.pop();
		if (e.to == t) {
			cnt++;
		}
		if (cnt == k) {
			return e.g;
		}
		for (int i = pre[e.to]; i != -1; i = edge[i].next) {
			ne.to = edge[i].to;
			ne.g = e.g + edge[i].w;
			ne.f = ne.g + dis[ne.to];
			que.push(ne);
		}
	}
	return -1;
}
int main() {
	int x, y, w, l;
	scanf("%d %d %d", &n, &m, &l);
	memset(pre1, -1, sizeof pre1);
	memset(pre, -1, sizeof pre);
	id = id1 = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		add(x, y, 1);
		add1(y, x, 1);
	}
	scanf("%d %d", &s, &t);
	k = 1;
	while (true) {
		spfa(t,n,pre1,edge1,dis);
		int ans = A_star(s,t,n,k,pre,edge,dis);
		if (ans == l) {
			puts("YES");
			return 0;
		}
		if (ans > l) {
			puts("NO");
			return 0;		
		}
	}
	return 0;
}
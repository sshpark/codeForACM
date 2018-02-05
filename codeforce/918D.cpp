#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 300005;
char str[maxn];
int head[maxn], deg[maxn], dp[maxn][27], id = 0;
queue<int> q;

struct node {int to, next;}edge[maxn];
inline void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = head[x];
    head[x] = id++;
}
int main(int argc, char const *argv[])
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    memset(head, -1, sizeof head);
    memset(deg, 0, sizeof deg);
    memset(dp, 0, sizeof dp);
    while (m--) {
        scanf("%d %d", &u, &v);
        add(u, v);
        deg[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (!deg[i]) {
            q.push(i);
            dp[i][str[i-1]-'a'] = 1;
        }
    int cnt = 0;
    while (!q.empty()) {
        int top =q.front(); q.pop();
        for (int i = head[top]; ~i; i = edge[i].next) {
            v = edge[i].to;
            dp[v][str[v-1]-'a'] = max(dp[v][str[v-1]-'a'], dp[top][str[v-1]-'a']+1);
            for (int j = 0; j < 26; j++) dp[v][j] = max(dp[v][j], dp[top][j]);
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
        cnt++;
    }
    if (cnt != n) {
        puts("-1");
    } else {
        int maxa = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 26; j++)
                maxa = max(maxa, dp[i][j]);
        printf("%d\n", maxa);
    }
    return 0;
}
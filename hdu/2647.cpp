#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
struct node {
    int to;
    int next;
}edge[20005];
int id;
int head[10005], in[10005];
inline void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = head[x];
    head[x] = id++;
}
int main(int argc, char const *argv[])
{
    int n, m, u, v;
    while(cin >> n >> m) {
        memset(head, -1, sizeof head);
        memset(in, 0, sizeof in);
        id = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            add(v, u);
            in[u]++;
        }
        queue<pii> q;
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (!in[i]) {
                q.push(pii(i, 888));
                sum += 888;
            }
        int x = 0;
        while (!q.empty()) {
            pii top = q.front(); q.pop();
            x++;
            for (int i = head[top.first]; i != -1; i = edge[i].next) {
                int e = edge[i].to;
                --in[e];
                if (!in[e]) {
                    q.push(pii(e, top.second+1));
                    sum += top.second+1;
                }
            }
        }
        if (x != n) {
            printf("-1\n");
        } else {
            printf("%d\n", sum);
        }
    }
    return 0;
}
// 4 3
// 1 2
// 3 2
// 2 4
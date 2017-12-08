#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
const int maxn = 505;
int n, m;
int main(int argc, char const *argv[])
{
    int u, v;
    while (~scanf("%d %d", &n, &m)) {
        int in[maxn];
        memset(in, 0, sizeof in);
        vector<int> p[maxn];
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int> > q;
        while (m--) {
            scanf("%d %d", &u, &v);
            p[u].push_back(v);
            in[v]++;
        }
        bool first = true;
        for (int i = 1; i <= n; i++)
            if (!in[i]) {
                ans.push_back(i);
                q.push(i);
            }
        while (!q.empty()) {
            u = q.top();
            q.pop();
            if (first)
                printf("%d", u), first = false;
            else
                printf(" %d", u);
            for (auto i : p[u]) {
                in[i]--;
                if (!in[i]) {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
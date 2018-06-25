#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 10005;
struct node {
    int next;
    int to;
    int wi;
}edge[maxn];
int T, n, m, u, v;
int head[maxn], id, d[maxn], p[maxn][25], gw[maxn][25], dist[maxn];
inline void add(int x, int y, int w) {
    edge[id].to = y;
    edge[id].wi = w;
    edge[id].next = head[x];
    head[x] = id++;
}
void dfs(int u){
    for(int i=head[u];i!=-1;i=edge[i].next){
        int to=edge[i].to;
        if(to==p[u][0])continue;
        d[to]=d[u]+1;
        dist[to]=dist[u]+edge[i].wi;
        p[to][0]=u; //p[i][0]存i的父节点
        dfs(to); 
    }
}
void init(){
    memset(gw, 0, sizeof gw);
    memset(dist, 0, sizeof dist);
    memset(head, -1, sizeof head);
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}
int lca(int a,int b){
    if(d[a]>d[b])swap(a,b); //b在下面 
    int f=d[b]-d[a];//f是高度差
    int ans = 0;
    for(int i=0;(1<<i)<=f;i++){//(1<<i)&f找到f化为2进制后1的位置，移动到相应的位置
        if((1<<i)&f) ans+=gw[b][i], b=p[b][i];//比如f=5(101),先移动2^0祖先，然后再移动2^2祖先
    }
    if(a!=b){
        for(int i=(int)log2(n);i>=0;i--){
            if(p[a][i]!=p[b][i]){//从最大祖先开始，判断a,b祖先，是否相同
                ans += gw[a][i];
                ans += gw[b][i];
                a=p[a][i]; b=p[b][i];//如不相同，a b同时向上移动2^j
            }
        }
        a=p[a][0];//这时a的father就是LCA
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int w;
    scanf("%d", &T);
    while (T--) {
        id = 0;
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs(1);
        while (m--) {
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u, v));
        }
    }

    return 0;
}
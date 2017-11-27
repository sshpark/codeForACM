#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
typedef pair<int,int> pii;
typedef long long LL;
const double PI=acos(-1.0);
const int N=200010;
const int M=1e5+7;
int bridge;
struct edge
{
    int to,nxt;
    int id,flag;
};
edge E[M<<1];
int head[N],tot;
int dfn[N],low[N],st[N],ts,top;
bool ins[N];
int rev[N];
 
void init()
{
    CLR(head,-1);
    tot=0;
    CLR(dfn,0);
    CLR(low,0);
    ts=top=0;
    CLR(ins,false);
    CLR(rev,INF);
    bridge=0;
}
inline void add(int s,int t,int id)
{
    E[tot].to=t;
    E[tot].flag=0;
    E[tot].id=id;
    E[tot].nxt=head[s];
    head[s]=tot++;
}
void Tarjan(int u,int id)
{
    dfn[u]=low[u]=++ts;
    ins[u]=1;
    st[top++]=u;
    int i,v;
    for (i=head[u]; ~i; i=E[i].nxt)
    {
        v=E[i].to;
        if(E[i].id==id)
            continue;
        if(!dfn[v])
        {
            Tarjan(v,E[i].id);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])
            {   
                bridge++;
                E[i].flag=true;
                E[i^1].flag=true;
            }
        }
        else if(ins[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        do
        {
            v=st[--top];
            ins[v]=0;
        }while (u!=v);
    }
}
void dfs(int u,int pre)
{
    rev[u]=min(rev[pre],u);
    ins[u]=1;
    for (int i=head[u]; ~i; i=E[i].nxt)
    {
        if(E[i].flag)
            continue;
        if(!ins[E[i].to])
            dfs(E[i].to,u);
    }
}
int main(void)
{
    int n,m,a,b,i;
    while (~scanf("%d%d",&n,&m))
    {
        init();
        for (i=0; i<m; ++i)
        {
            scanf("%d%d",&a,&b);
            add(a,b,i);
            add(b,a,i);
        }
        CLR(ins,false);
        for (i=1; i<=n; ++i)
            if(!dfn[i])
                Tarjan(i,-1);
        int sz=1;
        for (i=1; i<=n; ++i)
            if(!ins[i])
                dfs(i,i);
        printf("%d\n",bridge+1);
        for (i=1; i<=n; ++i)
            printf("%d%s",rev[i],i==n?"\n":" ");
    }
    return 0;
}
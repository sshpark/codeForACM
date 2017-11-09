#include<iostream>
#define clr(x) memset(x,0,sizeof(x))
#define clr_1(x) memset(x,-1,sizeof(x))
#define mod 1000000007
#define LL long long
using namespace std;
const int N=200010;
int n,m,q,k,T,u,v;
int pos[N],info[N];
LL pp,qq,tt,ans,all;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&pos[i]);
            if(pos[i]==m)
                pos[i]=0;
        }
        all=0;
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&u,&v);
            v=v%m;
            info[i]=(pos[u]-v+m)%m;
            all+=info[i];
        }
        n=q;
        sort(info+1,info+n+1);
        LL qq=0;
        ans=all;
        for(int i=n;i>=1;i--)
        {
            pp=m-(info[i]+qq);
            all-=(LL)info[i]+qq;
            all+=pp*(n-1);
            qq+=pp;
            if(all<ans)
                ans=all;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
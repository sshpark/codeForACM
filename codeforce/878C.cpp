#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

ll n, m, q;
ll p[maxn], d[maxn];

int main()
{
   //freopen("in.txt","r",stdin);
   int T;
   scanf("%d",&T);
   while(T--)
   {
       scanf("%lld%lld%lld",&n,&m,&q);
       for(int i=0;i<n;i++)  scanf("%lld",&p[i]);

       ll sum = 0;
       for(int i=0,j;i<q;i++)
       {
           ll t;
           scanf("%d%lld",&j,&t);
           d[i]=(p[j-1]-1-t%m+m)%m;
           sum=sum+d[i];
       }
       ll ans = (ll)1e18;
       // sort(d,d+q);
       for(int i=0;i<q;i++)
       {
               ans = min(ans, sum + i*m - q*d[i]);
       }
       cout<<ans<<endl;
   }
   return 0;
}
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
int a[20], num[20];
set<ll> ss;
inline ll getVal(int end) {
    ll ans = 0;
    for (int i = end; i >= 1; i--)
        ans += a[i]*pow(10, end-i);
    return ans;
}
ll ModMul(ll a,ll b,ll n)//快速积取模 a*b%n  
  {  
      ll ans=0;  
      while(b)  
      {  
          if(b&1)  
            ans=(ans+a)%n;  
          a=(a+a)%n;  
          b>>=1;  
      }  
      return ans;  
  }  
  ll ModExp(ll a,ll b,ll n)//快速幂取模 a^b%n  
  {  
      ll ans=1;  
      while(b)  
      {  
          if(b&1)  
            ans=ModMul(ans,a,n);  
          a=ModMul(a,a,n);  
          b>>=1;  
      }  
      return ans;  
  }  
  bool miller_rabin(ll n)//Miller-Rabin素数检测算法  
  {  
      ll i,j,a,x,y,t,u,s=10;  
      if(n==2)  
        return true;  
      if(n<2||!(n&1))  
        return false;  
      for(t=0,u=n-1;!(u&1);t++,u>>=1);//n-1=u*2^t  
      for(i=0;i<s;i++)  
      {  
          a=rand()%(n-1)+1;  
          x=ModExp(a,u,n);  
          for(j=0;j<t;j++)  
          {  
              y=ModMul(x,x,n);  
              if(y==1&&x!=1&&x!=n-1)  
                return false;  
              x=y;  
          }  
          if(x!=1)  
            return false;  
      }  
      return true;  
  }
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    for (int i = 2; i <= 16; i+=2)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (i % 6 != 0) {
                    for (int q = 1; q <= i; q++)
                        if (q > i/2) a[q] = k;
                        else a[q] = j;
                    sort(a+1, a+1+i);
                    do {
                        if (miller_rabin(getVal(i))) {
                            ss.insert(getVal(i));
                        }
                    }while(next_permutation(a+1, a+i+1));
                }
    int cnt = 1;
    for (auto i = ss.begin(); i != ss.end(); i++) {
        if (cnt % 50 == 0) printf("\n");
        else printf("%lld,", *i);
        cnt++;
    }
        
    printf("%d\n", (int)ss.size());
    return 0;
}
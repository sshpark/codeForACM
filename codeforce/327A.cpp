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
const int inf = 0x3f3f3f3f;
#define LOCAL

int a[105];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int s[101], t[101];  
    int n, ans, i, j, k, kk, max;  
    while(~scanf("%d", &n))  
    {  
        max = -1;  
        for(i=0; i<n; i++)  
            scanf("%d", &s[i]);  
  
        for(i=0; i<n; i++)  
        {  
            for(j=i; j<n; j++)  
            {  
                for(k=0; k<n; k++)  
                   t[k] = s[k];  
  
                for(kk=i; kk<=j; kk++)  
                {  
                    if(t[kk])  
                       t[kk] = 0;  
                    else t[kk] = 1;  
                }  
                ans = 0;  
               for(kk=0; kk<n; kk++)  
               {  
                   if(t[kk])  
                      ans++;  
               }  
               if(ans>max)  
                  max = ans;  
            }  
        }  
        printf("%d\n", max);  
    }  
   

    return 0;
}
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
int a[1005],b[1005],f[1005]; 


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
    int T,i,n1,n2,j,k,max; 
    cin>>T; 
    while (T--)
    { 
        scanf("%d", &n1);
        for(j = 1; j <= n1; j++) 
            scanf("%d", &a[j]); 
        scanf("%d", &n2);
        for(j=1;j<=n2;j++) 
            scanf("%d", &b[j]);
        memset(f,0,sizeof(f)); 
        for(j=1;j<=n1;j++) 
        { 
            max=0; 
            for(k=1;k<=n2;k++) 
            { 
                if(a[j]>b[k]&&max<f[k]) 
                    max=f[k]; 
                if(a[j]==b[k]) 
                    f[k]=max+1; 
            } 
        } 
        max=0; 
        for(j=1;j<=n2;j++) 
            if(f[j]>max) 
                max=f[j]; 
        cout<<max<<endl; 
    } 
    return 0; 
}
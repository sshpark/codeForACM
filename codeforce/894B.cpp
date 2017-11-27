#include <iostream>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll quick(ll a,ll b,ll c)  
{  
    ll ans=1;  
    a=a%c;  
    while(b!=0)  
    {  
        if(b&1) ans=(ans*a)%c;  
        b>>=1;  
        a=(a*a)%c;  
    }  
    return ans;  
}

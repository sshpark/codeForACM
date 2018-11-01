#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ans=0;
    for(int i=1901;i<=2000;i++)
    {
        for(int j=3;j<=14;j++)
        {
            int w,c,y,m,d;
            c=i/100;y=i%100;m=j;d=1;
            w=(c/4-2*c+y+y/4+(13*(m+1))/5+d-1)%7;
            if(w==0)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}


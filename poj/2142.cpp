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
int exgcd(int a, int b, int &x, int &y)
{
	int d, t;
	if (b == 0){x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a/b*y;
	return d;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int a, b, c, x, y;

	while (~scanf("%d %d %d", &a, &b, &c) && a+b+c)
	{
		bool flag = false;
		if (a < b)
		{
			swap(a, b);
			flag = true;
		}
		int r = exgcd(a, b, x, y);
		a/=r;b/=r;c/=r;  
        x*=c;y*=c;  
        int t=y/a;  
        int rx,ry;  
        while(y-a*t<0)  
            t--;  
        int x1,y1,x2,y2;  
        x1=abs(x+b*t);y1=abs(y-a*t);  
        t++;  
        x2=abs(x+b*t);y2=abs(y-a*t);  
        if((x1+y1<x2+y2)||((x1+y1==x2+y2)&&(x1*a+y1*b<x2*a+y2*b)))  
            rx=x1,ry=y1;  
        else  
            rx=x2,ry=y2;  
        if(flag)  
            cout<<ry<<' '<<rx<<endl;  
        else  
            cout<<rx<<' '<<ry<<endl; 
	}

    return 0;
}
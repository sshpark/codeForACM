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
int T, n, m;
int a[20];

int gcd(int a, int b)  
{  
 if (a < b)  
  swap(a, b);  
  
 if (b == 0)  
  return a;  
 else  
  return gcd(b, a%b);  
}  

int lcm(int a, int b)  
{  
 return a*b/gcd(a, b);  
} 

int nlcm(int *a, int n)  
{  
 if (n == 1)  
  return *a;  
 else  
  return lcm(a[n-1], nlcm(a, n-1));  
}  

int countone(int x)
{
	int sum = 1;
	while(true)
	{
		if (x*sum >= n)
		{
			if (x*sum > n)
				sum--;
			return sum;
		}
		sum++;
	}
}

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	
	cin >> T;

	while(T--)
	{
		scanf("%d %d", &n, &m);
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &a[i]);
			ans += countone(a[i]);
		}
		if (m != 1)
		{
			int minG = nlcm(a, m);
			ans -= 2*countone(minG);
		}
		printf("%d\n", ans);
		
		
	}

    return 0;
}
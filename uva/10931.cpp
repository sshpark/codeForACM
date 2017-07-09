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
char str[100];
int countOne(int n)
{
	int sum = 0;

	while (n != 0)
	{
		sum += n%2;
		n /= 2;
	}
	return sum;
}

void printstr(int n)
{
	int i = 0;
	while (n != 0)
	{
		str[i] = n % 2 + '0';
		n /= 2;
		i++;
	}
	str[i] = '\0';
}

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	

	while (~scanf("%d", &n) && n)
	{
		printstr(n);
		printf("The parity of ");
		for (int i = strlen(str) - 1; i >= 0; i--)
			printf("%c", str[i]);
		printf(" is %d (mod 2).\n", countOne(n));
	}

    return 0;
}
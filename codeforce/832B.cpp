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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	string goodStr, patternStr, str;
	int n;

	while (cin >> goodStr)
	{
		cin >> patternStr;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int flag = 0;
			for (int j = 0; j < str.size(); j++)
			{
				flag = 0;
				if (patternStr[j] <= 'z' && patternStr[j] >= 'a')
				{
					if (str[j] != patternStr[j])
					{
						// printf("1\n");
						puts("NO");
						flag = 1;
						break;
					}
				}
				else
				{
					if (patternStr[j] == '*')
					{
						int ok = 0;
						int end = str.size() - 1;

						for (int k = j+1; k < str.size(); k++)
							if (str[k] <= goodStr[goodStr.size()-1] && str[k] >= 'a')
							{
								end = k;
								break;
							}
						for (int k = j; k < end; k++)
						{
							
							for (int q = 0; q < goodStr.size(); q++)
								if (str[k] == goodStr[q])
								{
									// printf("3\n");
									puts("NO");
									flag = 1;
									ok = 1;
									break;
								}
							if (ok)
								break;
						}
						if (end >= 1)
						j += end - 1;
					}
					else if (patternStr[j] == '?')
					{
						// printf("%c", patternStr[j]);
						int ok = 0;
						for (int q = 0; q < goodStr.size(); q++)
							if (str[j] == goodStr[q])
							{
								ok = 1;
								break;
							}
						if (!ok)
						{
							// printf("4\n");
							flag = 1;
							puts("NO");
						}
					}
				}
				if (flag)
					break;
				if (j >= patternStr.size() && patternStr[j] == '\0' && flag == 1)
				{
					// printf("sss\n");
					flag = 1;
					puts("NO");
					break;
				}
			}
			if (!flag)
				puts("YES");
		}
	}

    return 0;
}
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
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	string s1, s2, s3;

	while (getline(cin, s1))
	{
		if (s1 == "ENDOFINPUT")
			break;
		if (s1 == "START")
		{
			getline(cin, s2);
			//cout << s2 << endl;
			for (int i = 0; i < s2.size(); i++)
			{
				if (s2[i] <= 'Z' && s2[i] >= 'A')
					printf("%c", 'A' + (s2[i] - 'A' + 21)%26);
				else
					printf("%c", s2[i]);
			}
		}
		getline(cin, s3);
		printf("\n");
	}



    return 0;
}
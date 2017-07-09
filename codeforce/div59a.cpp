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
//#define LOCAL

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	map<string, string>::iterator it;
	std::vector<string> ss, ss1, ss2, ss3;
	while (cin >> n)
	{
		string s, s1;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> s1;
			if (s1 == "rat")
				ss.push_back(s);
			if (s1 == "woman" || s1 == "child")
				ss1.push_back(s);
			if (s1 == "man")
				ss2.push_back(s);
			if (s1 == "captain")
				ss3.push_back(s);
		}
		for (int i = 0; i < ss.size(); i++)
			cout << ss[i] << endl;
		for (int i = 0; i < ss1.size(); i++)
			cout << ss1[i] << endl;
		for (int i = 0; i < ss2.size(); i++)
			cout << ss2[i] << endl;
		for (int i = 0; i < ss3.size(); i++)
			cout << ss3[i] << endl;
	}
    return 0;
}
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
const int maxn = 50;
int ans = 0;
struct trie
{
	int num;
	struct trie *next[maxn];
	trie() {
		num = 0;
		for (int i = 0; i < maxn; i++)
			next[i] = NULL;
	}
};

struct trie *root = new trie();

void insert(char *str)
{
	int len = strlen(str);
	struct trie *p = root, *q;
	for (int i = 0; i < len; i++)
	{
		int id;
		if(str[i] >= 'a' && str[i] <= 'z') id = str[i] - 'a';
        else if(str[i] >= '0' && str[i] <= '9')id = str[i]- '0' + 27;
        else id = 39;
		
		if (p -> next[id] == NULL)
		{
			p -> next[id] = new trie();
			if(id == 39 && i != 0) ans++;
		}
		p -> num++;
		p = p -> next[id];
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;	
	char str[1005], in[1005];
	while (~scanf("%d", &n))
	{

		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			insert(str);
		}
		printf("%d\n", ans);
	}

    return 0;
}
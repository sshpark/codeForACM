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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
const int maxn = 50;
int ans = 0;
struct trie
{
	int num;
	char c;
	struct trie *next[maxn];
	trie() {
		num = 0;
		for (int i = 0; i < maxn; i++)
			next[i] = NULL;
	}
};

struct trie *root = new trie();

void create(char *str)
{
   int len = strlen(str);
   trie *p = root, *q;
   for (int i = 0; i < len; i++)
   {
      int id = str[i] - 'a';
      if (p -> next[id] == NULL)
      {
         q = (trie *)malloc(sizeof(trie));
         q -> num = 1;
         for (int j = 0; j < 26; j++)
            q -> next[j] = NULL;
         p -> next[id] = q;
         p = p -> next[id];
      }
      else
      {
         p -> next[id] -> num++;
         p = p -> next[id];
      }
      
   }
   // p -> num = -1;
}

int search(char *str)
{
   int len = strlen(str);
   trie *p = root;
   for (int i = 0; i < len; i++)
   {
      int id = str[i] - 'a';
      p = p -> next[id];
      if (p == NULL)
         break;
   }
   if (p == NULL)
      return 0;
   else
      return p -> num;
}

char str[10005][1005];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;	
	char in[1005];
	while (~scanf("%d", &n))
	{

		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		char sf[1005];
		int k = 0;
		REP(i, 0, n)
		{
			ms(sf);
			k = 0;
			int len = strlen(str[i]);
			REP(j, 1, len)
			{
				if (j == len - 1)
				{
					create(sf);	
					continue;
				}
				if (str[i][j] == '/')
				{
					create(sf);
					ms(sf);
					k = 0;
				}
				else
					sf[k++] = str[i][j];
			}
			
		}
		// char r[4] = "p11";
		// printf("%d\n", search(r));
		REP(i, 0, n)
		{
			printf("/");

			ms(sf);
			k = 0;
			int len = strlen(str[i]);
			char re[100];
			int rek = 0;
			while(str[i][len-1] != '/')
			{
				len--;
				re[rek++] = str[i][len];
			}
			// printf("%s\n", re);
			REP(j, 1, len)
			{
				if (str[i][j] == '/')
				{
					if (search(sf) == 1)
					{
						if (j == len-1)
							printf("%s/", sf);
						else
							printf("%s-", sf);
					}
					else
						printf("%s/", sf);
					ms(sf);
					k = 0;
				}
				else
					sf[k++] = str[i][j];
			}
			for (int j = rek-1; j >= 0; j--)
			printf("%c", re[j]);
			printf("\n");
		}
	}

    return 0;
}
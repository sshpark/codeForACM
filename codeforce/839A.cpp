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
#include <bitset>
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
#deine LOCAL

typedef struct trie
{
   int val;
   struct trie *next[2];
   trie()
   {
      val = 0;
      fill(next, next+2, nullptr);
   }
} trie;

trie *root;

void insert(int x)
{
   bitset<33> bit = x;
   trie *p = root;
   for (int i = 32; i >= 0; i--)
   {
      int id = bit[i];
      if (p -> next[id] == NULL)
      {
         trie *q = new trie();
         p -> next[id] = q;
         p = q;
      }
      else
         p = p -> next[id];
   }
   p -> val = x;
}

int query(int x)
{
   trie *p = root;
   bitset<33> bit = x;
   for (int i = 32; i >= 0; i--)
   {
      int id = bit[i];
      if (p -> next[id^1])
         p = p -> next[id^1];
      else
         p = p -> next[id];
   }
   return p -> val;
}




int main(int argc, char * argv[]) 
{
   #ifdef LOCAL
   freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
   //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
   #endif

   int T, n, m, x;
   scanf("%d", &T);
   int kase = 0;
   while (T--)
   {
//      printf("Case #%d:\n", ++kase);
      root = new trie();   
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
         scanf("%d", &x);
         insert(x);
      }
      int maxa = -inf;
      for (int i = 0; i < n; i++)
      {
         scanf("%d", &x);
         printf("%d\n", x ^ query(x));
      }
      
      delete(root);
   }

    return 0;
}
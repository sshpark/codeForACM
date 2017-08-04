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
int n, k;
string op;
struct Play
{
	int fruit[10];
	int animal;
	int fORa;
}player[10];

struct Cur
{
	int player[15];
	int fruit[10];
	int animal[10];
	int pai;
}Game;

bool isRing()
{
	int fruitNum = 0;
	for (int i = 0; i < 4; ++i)
		fruitNum += Game.fruit[i];
	for (int i = 0; i < 4; ++i)
		if (Game.fruit[i] == 5)
			return true;
	if (Game.animal[0] > 0 && fruitNum >= 1 && Game.fruit[3] == 0)
		return true;
	if (Game.animal[1] > 0 && fruitNum >= 1 && Game.fruit[1] == 0)
		return true;
	if (Game.animal[2] > 0 && fruitNum >= 1)
		return true;
	return false;
	
}
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	
	while (~scanf("%d %d", &n, &k))
	{
		ms(Game.fruit);
		ms(Game.animal);
		Game.pai = 0;
		for (int i = 0; i < n; ++i)
			Game.player[i] = 10000000;
		for (int i = 0; i < n; ++i)
		{
			ms(player[i].fruit);
			player[i].fORa = -1;
			player[i].animal = 0;
		}
		int f, s, curplayid = 0;
		while(k--)
		{
			cin >> op;
			if (op == "Fruit")
			{
				scanf("%d", &f);
				Game.player[curplayid]--;
				Game.pai++;
				if (player[curplayid].fORa == -1 || player[curplayid].fORa == 0)
					for (int i = 0; i < 4; i++)
						Game.fruit[i] -= player[curplayid].fruit[i];
				if (player[curplayid].fORa == 1)
					Game.animal[player[curplayid].animal]--;
				ms(player[curplayid].fruit);
				player[curplayid].animal = 0;
				for (int i = 0; i < f; i++)
				{
					scanf("%d", &s);
					player[curplayid].fruit[s]++;
					Game.fruit[s]++;
				}
				player[curplayid].fORa = 0;
				curplayid = (curplayid+1)%n;
			}
			else if (op == "Animal")
			{
				Game.player[curplayid]--;
				Game.pai++;
				scanf("%d", &f);
				if (player[curplayid].fORa == -1 || player[curplayid].fORa == 0)
					for (int i = 0; i < 4; i++)
						Game.fruit[i] -= player[curplayid].fruit[i];
				if (player[curplayid].fORa == 1)
					Game.animal[player[curplayid].animal]--;
				player[curplayid].animal = f;
				Game.animal[f]++;
				player[curplayid].fORa = 1;
				curplayid = (curplayid+1)%n;
			}
			else
			{
				scanf("%d", &f);
				if (isRing())
				{
					Game.player[f] += Game.pai;
					Game.pai = 0;
					ms(Game.fruit);
					ms(Game.animal);
					for (int i = 0; i < n; ++i)
					{
						ms(player[i].fruit);
						player[i].animal = 0;
					}
					curplayid = f;

				}
				else
				{
					Game.player[f] -= n - 1;
					for (int i = 0; i < n; ++i)
						if (i != f)
							Game.player[i]++;
					curplayid = f;
				}
			}

		}
		for (int i = 0; i < n; ++i)
		{
			printf("%d\n", Game.player[i]);
		}
	}

    return 0;
}
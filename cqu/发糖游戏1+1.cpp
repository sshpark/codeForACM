#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long 
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
const int N = 110000;
ll SUM[N << 2];
int lazy[N << 2];
void pushUp(int rt)
{
	SUM[rt] = SUM[rt << 1] + SUM[rt << 1 | 1];
}

void pushDown(int rt, int m)
{
	if (lazy[rt])
	{
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		SUM[rt << 1] += lazy[rt]*(m-(m >> 1));
		SUM[rt << 1 | 1] += lazy[rt]*(m >> 1);
		lazy[rt] = 0;
	}
}

void build(int l, int r, int rt)
{
	lazy[rt] = 0;
	if (l == r)
	{
		SUM[rt] = 0;
		return ;
	}
	int m = (l+r) >> 1;
	build(lson);
	build(rson);
	pushUp(rt);
}

void update1(int p, int add, int l, int r, int rt)
{
	if (l == r)
	{
		SUM[rt] += add;
		return ;
	}
	int m = (l+r) >> 1;
	if (l <= m)
		update1(p, add, lson);
	else
		update1(p, add, rson);
	pushUp(rt);
}

ll query1(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		return SUM[rt];
	}
	int m = (l+r) >> 1;
	ll ret = 0;
	if (L <= m)
		ret += query1(L, R, lson);
	if (R > m)
		ret += query1(L, R, rson);
	return ret;
}


void update2(int L, int R, int c, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		lazy[rt] += c;
		SUM[rt] += c*(r-l+1);
		return;
	}
	pushDown(rt, r-l+1);
  int m = (l + r) >> 1;
  if (L <= m) update2(L , R , c , lson);
  if (m < R) update2(L , R , c , rson);
  pushUp(rt);
}

ll query2(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return SUM[rt];
  }
  pushDown(rt , r - l + 1);
  int m = (l + r) >> 1;
  ll ret = 0;
  if (L <= m) ret += query2(L , R , lson);
  if (m < R) ret += query2(L , R , rson);
  return ret;
}
int main()
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	int T, m, n;
	scanf("%d", &T);
	string op;
	while (T--)
	{
		memset(SUM, 0, sizeof(SUM));
		memset(lazy, 0, sizeof(lazy));
		scanf("%d", &n);
		build(1, n, 1);
		getchar();
		getline(cin, op);
		scanf("%d", &m);
		int a, b, c, d;

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a == 0)
				update1(b, c, 1, n, 1);
			else
			{
				printf("%lld\n", query1(b, c, 1, n, 1));
			}
		}
		op.clear();
		getchar();
		getline(cin, op);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &a);
			if (a == 0)
			{
				scanf("%d %d %d", &b, &c, &d);
				update2(b, c, d, 1, n, 1);
			}
			else if (a == 1)
			{
				scanf("%d", &d);
				printf("%lld\n", query2(d, d, 1, n, 1));	
			}
		}
	}

}
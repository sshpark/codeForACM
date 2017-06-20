#include <iostream>
#include <stdio.h>
using namespace std;
bool is_huiwen(int h, int m)
{
	if (h/10 == m%10 && h%10 == m/10)
		return true;
	return false;
}
int main()
{
	int h, m;
	int cnt = 0;
	scanf("%d:%d", &h, &m);
	if (is_huiwen(h, m))
		printf("0\n");
	else
		while (true)
		{
			m += 1;
			cnt++;
			if (m >= 60)
			{
				m = 0;
				h++;
			}
			if (h >= 24)
			{
				h = 0;
			}
			if (is_huiwen(h, m))
			{
				printf("%d\n", cnt);
				break;
			}
		}
		return 0;
}

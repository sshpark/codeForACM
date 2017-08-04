#include <stdio.h>
int phi(int n)
{
	int rea = n;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			rea = rea - rea/i;
			do
				n /= i;
			while(n % i == 0);
		}
	}
	if (n > 1)
		rea = rea - rea/n;
	return rea;

}
int main()
{
	int n;
	while (~scanf("%d", &n) && n)
	{
		printf("%d\n", phi(n-1));
	}
}
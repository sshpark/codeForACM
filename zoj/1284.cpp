#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int getsum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	return sum;
}
int main()
{
	freopen("data.in", "r", stdin);
	int n;
	puts("PERFECTION OUTPUT");

	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			puts("END OF OUTPUT");
			break;
		}
		
		int num = getsum(n);
		if (num == n)
			printf("%5d  %s\n", n, "PERFECT");
		else if (num > n)
			printf("%5d  %s\n", n, "ABUNDANT");
		else
			printf("%5d  %s\n", n, "DEFICIENT");
	}
	return 0;
}
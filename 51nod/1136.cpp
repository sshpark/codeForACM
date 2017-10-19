#include <iostream>
#include <math.h>
using namespace std;
int getphi(int n) {
	int ret = n, len = sqrt(n);
	for (int i = 2; i <= len; i++)
		if (n % i == 0) {
			ret = ret/i*(i-1);
			while (n%i == 0) n /= i;
		}
	if (n > 1)
		ret = ret/n*(n-1);
	return ret;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	printf("%d\n", getphi(n));
	return 0;
}
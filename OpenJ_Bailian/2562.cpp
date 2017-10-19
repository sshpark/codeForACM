#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char a[15], b[15];
	while (~scanf("%s %s", a, b)) {
		if (!strcmp(a, "0") && !strcmp(b, "0")) break;
		int la = strlen(a), lb = strlen(b);
		la--, lb--;
		int c = 0, sum = 0;
		while (la >= 0 && lb >= 0) {
			c = ((a[la] - '0') + (b[lb] - '0') + c)/10;
			if (c) sum++;
			la--, lb--;
		}
		while (la >= 0) {
			c = ((a[la] - '0') + c)/10;
			if (c) sum++;
			la--;
		}
		while (lb >= 0) {
			c = ((b[lb] - '0') + c)/10;
			if (c) sum++;
			lb--;
		}
		if (sum == 1) printf("%d carry operation.\n", sum);
		else if (sum > 1) printf("%d carry operations.\n", sum);
		else puts("No carry operation.");
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char str[55];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i+=2)
			putchar(str[i+1]), putchar(str[i]);
		putchar('\n');
	}
	return 0;
}
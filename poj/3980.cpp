#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		printf("%d\n", a-a/b*b);
	}
	return 0;
}
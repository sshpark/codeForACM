#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	char str[105];
	cin >> str;
	int len = strlen(str);
	char s = 'a';
	int sum = 0;

	for (int i = 0; i < len; i++) {
		sum += min((str[i]-s+26)%26, (s-str[i]+26)%26);
		s = str[i];
	}
	printf("%d\n", sum);
	return 0;
}
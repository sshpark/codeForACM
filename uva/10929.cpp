#include <iostream>
using namespace std;
bool getcharsum(char *str)
{
	int suma = 0, sumb = 0;
	for (int i = 0; i < strlen(str); i += 2)
	{
		suma += str[i] - '0';
		if (i+1 < strlen(str))
			sumb += str[i+1] - '0';
	}
	if ((suma-sumb)%11 == 0)
		return true;
	else
		return false;

}
int main()
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	char str[1005];

	while (~scanf("%s", str))
	{
		if (str[0] == '0' && strlen(str) == 1)
			break;
		if (getcharsum(str))
			printf("%s is a multiple of 11.\n", str);
		else
			printf("%s is not a multiple of 11.\n", str);
	}
}
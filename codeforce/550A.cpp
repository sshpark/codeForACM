#include <iostream>
#include <string.h>
#include <stdio.h> 
using namespace std;
int main(int argc, char const *argv[])
{
	char str[100005], *p;
	scanf("%s", str);
	if ((p = strstr(str, "AB")) and strstr(p+2, "BA")) puts("YES");
	else if ((p = strstr(str, "BA")) and strstr(p+2, "AB")) puts("YES");
	else puts("NO");
	return 0;
}
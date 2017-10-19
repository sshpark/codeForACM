#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 2005;
char str[maxn];
int main(int argc, char const *argv[])
{
	int i, j, k;
	while (~scanf("%s", str)) {
		int a, b, c1, c2;
		a = b = c1 = c2 = 0;
		int len = strlen(str);
		int num = 0;
		int flag = 1;
		for (i = 0; i < len; i++) {
			if (str[i] <= '9' && str[i] >= '0')
				num = num*10+str[i]-'0';
			else {
				if (str[i] == 'x') {
					if (num) a += num*flag;
					else {
						if (i > 0 && str[i-1] == '0')
							continue;
						a += flag;
					}
				}
				else 
					if (num) c1 += num*flag;
				num = 0;
				if (str[i] == '+') flag = 1;
				else if (str[i] == '-') flag = -1;
			}
			if (str[i] == '=')
				break;
		}
		flag = 1;
		for (i++; i < len; i++) {
			if (str[i] <= '9' && str[i] >= '0')
				num = num*10+str[i]-'0';
			else {
				if (str[i] == 'x') {
					if (num) b += num*flag;
					else {
						if (i > 0 && str[i-1] == '0')
							continue;
						b += flag;
					}
				}
				else 
					if (num) c2 += num*flag;
				num = 0;
				if (str[i] == '+') flag = 1;
				else if (str[i] == '-') flag = -1;
			}
		}
		if (num) c2 += num*flag;
		if (a == b) puts(c1 != c2 ? "IMPOSSIBLE" : "IDENTITY");
		else {
			int sum = a - b;
			int res = c2 - c1;
			if (sum < 0) {
				res *= -1;
				sum *= -1;
			}
			printf("%d\n", res/sum);
		}		
	}
	return 0;
}
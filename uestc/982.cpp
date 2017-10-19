#include <iostream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[105];
int re = 0;
void get(int n) {
	int p1=2;
    while(p1*p1<=n)
    {
        while(n%p1==0)
        {
            a[re++] = p1;
            n=n/p1;
        }
        p1++;
    }
    if(n>1) a[re++] = n;
}
int main(int argc, char const *argv[])
{
	int n;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		re = 0;
		get(n);
		for (int i = 0; i < re; i++)
			if (i == 0)
				printf("%d=%d", n, a[i]);
			else
				printf("*%d", a[i]);
		printf("\n");
	}
	return 0;
}
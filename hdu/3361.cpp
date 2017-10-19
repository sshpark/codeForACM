#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		printf("%c", x);
	}
	return 0;
}
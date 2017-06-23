#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char str[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char ins[1000];
int main()
{
	while (cin.getline(ins, 1000))
	{
		for (int i = 0; i < strlen(ins); i++)
		{
			if (ins[i] == ' ')
				printf(" ");
			for (int j = 0; j < strlen(str)-1; j++)
			{
				if (ins[i] == str[j+1])
				{
					printf("%c", str[j]);
					break;
				}
			}
		}
		printf("\n");
	}
}

#include <iostream>
#include <string>
using namespace std;
char map[15][15];
char shi[15][15];
int countDilei(int i, int j)
{
	int sum = 0;
	if (map[i-1][j] == '*')
		sum++;
	if (map[i][j-1] == '*')
		sum++;
	if (map[i-1][j-1] == '*')
		sum++;
	if (map[i+1][j] == '*')
		sum++;
	if (map[i][j+1] == '*')
		sum++;
	if (map[i+1][j+1] == '*')
		sum++;
	if (map[i-1][j+1] == '*')
		sum++;
	if (map[i+1][j-1] == '*')
		sum++;
	return sum;
}
int main()
{
	freopen("data.in", "r", stdin);
	int n;
	string s;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = '\0';
				shi[i][j] = '\0';
			}
		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			for (int j = 1; j <= n; j++)
				map[i][j] = s[j-1];
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			for (int j = 1; j <= n; j++)
				shi[i][j] = s[j-1];
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (shi[i][j] == 'x' && map[i][j] == '.')
					shi[i][j] = countDilei(i, j) + '0';
				if (shi[i][j] == 'x' && map[i][j] == '*')
				{
					flag = 1;
				}
			}
		}
		if (flag)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
					if (map[i][j] == '*')
						shi[i][j] = '*';
			}
		}
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << shi[i][j];
			cout << endl;
		}
		
	}
}

#include <iostream>
#include <string>
using namespace std;
char map[105][105];
char re[105][105];
char judge(char a, char b)
{
	if ((a == 'R' && (b == 'R' || b == 'S')))
		return 'R';
	else if ((a == 'S' && b == 'R'))
		return 'R';
	else if ((a == 'S' && (b == 'S' || b == 'P')))
		return 'S';
	else if (a == 'P' && b == 'S')
		return 'S';
	else if ((a == 'P' && (b == 'P' || b == 'R')))
		return 'P';
	else
		return 'P';
}


int main()
{
	int T, r, c, n;
	string s;
	cin >> T;

	while(T--)
	{
		cin >> r >> c >> n;

		for (int i = 1; i <= r; i++)
		{
			cin >> s;
			for (int j = 1; j <= c; j++)
			{
				map[i][j] = s[j-1];
				re[i][j] = s[j-1];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < r; j++)
				for (int k = 1; k < c; k++)
				{
					re[j+1][k] = judge(map[j][k], map[j+1][k]);
					re[j][k+1] = judge(map[j][k], map[j][k+1]);
					re[j-1][k] = judge(map[j][k], map[j-1][k]);
					re[j][k-1] = judge(map[j][k], map[j][k-1]);
				}
			for (int j = 1; j <= r; j++)
				for (int k = 1; k <= c; k++)
				{
					map[j][k] = re[j][k];
				}
		}

		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
				cout << re[i][j];
			cout << endl;
		}
	}		
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
char map[5][5];

bool isRight()
{
	int Xwin = 0, Owin = 0, X = 0, O = 0;
	if ((map[1][1] == 'X' && map[1][2] == 'X' && map[1][3] == 'X') || (map[2][1] == 'X' && map[2][2] == 'X' && map[2][3] == 'X') || (map[3][1] == 'X' && map[3][2] == 'X' && map[3][3] == 'X') || 
		(map[1][3] == 'X' && map[3][3] == 'X' && map[2][3] == 'X') || (map[1][2] == 'X' && map[2][2] == 'X' && map[3][2] == 'X') || (map[1][1] == 'X' && map[2][1] == 'X' && map[3][1] == 'X') || 
		(map[1][1] == 'X' && map[2][2] == 'X' && map[3][3] == 'X') || (map[1][3] == 'X' && map[2][2] == 'X' && map[3][1] == 'X'))
		Xwin = 1;
	if ((map[1][1] == 'O' && map[1][2] == 'O' && map[1][3] == 'O') || (map[2][1] == 'O' && map[2][2] == 'O' && map[2][3] == 'O') || (map[3][1] == 'O' && map[3][2] == 'O' && map[3][3] == 'O') || 
		(map[1][3] == 'O' && map[3][3] == 'O' && map[2][3] == 'O') || (map[1][2] == 'O' && map[2][2] == 'O' && map[3][2] == 'O') || (map[1][1] == 'O' && map[2][1] == 'O' && map[3][1] == 'O') || 
		(map[1][1] == 'O' && map[2][2] == 'O' && map[3][3] == 'O') || (map[1][3] == 'O' && map[2][2] == 'O' && map[3][1] == 'O'))
		Owin = 1;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (map[i][j] == 'X')
				X++;
			if (map[i][j] == 'O')
				O++;
		}
	//cout << Xwin << Owin << X << O << endl;
	if (O > X || X - O >= 2 || (Xwin && Owin) || (Owin && (O != X)) || (Xwin && (O == X)))
		return false;
	return true;
}
int main()
{
	freopen("data.in", "r", stdin);
	int T;
	string s;
	cin >> T;

	while (T--)
	{
		for (int i = 1; i <= 3; i++)
		{
			cin >> s;
			for (int j = 1; j <= 3; j++)
				map[i][j] = s[j-1];
		}

		if (isRight())
			puts("yes");
		else
			puts("no");
	}
  return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int a, b, c;
		a = n/2;
		b = (n - a)*2/3;
		c = n - a - b;
		cout << ceil(a/10.0) + ceil(b/10.0) + ceil(c/10.0) << endl;
	}
	return 0;
}
	
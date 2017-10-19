#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a, b, f, k, x;
	cin >> a >> b >> f >> k;
	int ans = 0, t = b;
	for (int i = 0; i <= k; i++) {
		if (i == 0) x = f;
		else if (i == k) x = k & 1 ? a - f : f;
		else {
			if (i & 1) x = 2*(a-f);
			else x = 2*f;
		}
		if (x > b) {
			puts("-1");
			return 0;
		}
		if (t < x) {
			t = b;
			ans++;
		}
		t -= x;
	}
	printf("%d\n", ans);
	return 0;
}
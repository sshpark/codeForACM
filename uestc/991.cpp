#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 66600;
bool isp[maxn];
int p[maxn];
int cnt = 0;
void shai() {
	memset(isp, true, sizeof isp);
	for (int i = 2; i < maxn; i++)
		if (isp[i]) {
			p[cnt++] = i;
			for (unsigned long long j = i*i; j < maxn; j+=i)
				isp[j] = false;
		}
}
int main(int argc, char const *argv[])
{
	int a, b;
	shai();
	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int pos = lower_bound(p, p+cnt, a) - p;
		while (p[pos] <= b && p[pos] >= a) {
			cout << p[pos] << " ";
			pos++;
		}
		
		cout << endl;
	}
	return 0;
}
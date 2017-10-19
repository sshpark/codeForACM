#include <set>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	string str;
	set<string> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (s.find(str) == s.end()) puts("NO");
		else puts("YES");
		s.insert(str);
	}
	return 0;
}
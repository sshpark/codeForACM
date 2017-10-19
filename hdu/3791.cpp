#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, rt;
	char str[15];
	int tree[2005], tree1[2005];
	
	while (cin >> n && n) {
		cin >> str;
		int len = strlen(str);
		memset(tree, -1, sizeof tree);
		tree[1] = str[0] - '0';
		for (int i = 1; i < len; i++) {
			int j = 1, num = str[i] - '0';
			while (tree[j] != -1) {
				if (num == tree[j]) break;
				if (num > tree[j]) j = j<<1|1;
				if (num < tree[j]) j = j<<1;
			}
			tree[j] = num;
	 	}
	 	while (n--) {
	 		cin >> str;
	 		int len = strlen(str);
	 		memset(tree1, -1, sizeof tree1);
	 		tree1[1] = str[0] - '0';
	 		for (int i = 1; i < len; i++) {
				int j = 1, num = str[i] - '0';
				while (tree1[j] != -1) {
					if (num == tree1[j]) break;
					if (num > tree1[j]) j = j<<1|1;
					if (num < tree1[j]) j = j<<1;
				}
				tree1[j] = num;
		 	}
		 	int flag = 1;
		 	for (int i = 1; i < len; i++) 
		 		if (tree1[i] != tree[i]) {
		 			flag = 0;
		 			break;
		 		}
		 	if (flag) puts("YES");
		 	else puts("NO");
		}
 	}
	return 0;
}
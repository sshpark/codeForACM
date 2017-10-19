#include <bits/stdc++.h>
using namespace std;
struct trie {
	int cnt;
	struct trie *next[30];
	trie() {
		cnt = 1;
		for (int i = 0; i < 30; i++) next[i] = NULL;
	}
};
trie *root = new trie;
void insert(char *str) {
	trie *p = root, *q;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p -> next[id] == NULL) {
			q = new trie();
			p -> next[id] = q;
			p = p -> next[id];
		}
		else {
			p -> next[id] -> cnt++;
			p = p -> next[id];
		}
	}
}
int search(char *str) {
	int len = strlen(str);
	trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		p = p -> next[id];
		if (p == NULL) break;
	}
	if (p == NULL) return 0;
	return p -> cnt;
}
int main() {
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	char str[20];
	while (true) {
		scanf("%s", str);
		if (str[0] == 'E' &&str[1] == 'N' && str[2] == 'D') {
			break;
		}
		insert(str);
	}
	while (~scanf("%s", str))
		printf("%d\n", search(str));
}
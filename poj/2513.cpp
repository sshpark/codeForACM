#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int emax = 250005;
int deg[emax<<1], pre[emax<<1];
struct trie {
    int id;
    struct trie *next[30];
    trie() {
        for (int i = 0; i < 30; i++) next[i] = NULL;
        id = -1;
    }
};
trie *root = new trie;
inline void insert(char *str, int cnt) {
    trie *p, *q;
    p = root;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int id = str[i]-'a';
        if (p->next[id] == NULL) {
            q = new trie;
            p -> next[id] = q;
        }
        p = p -> next[id];
    }
    p -> id = cnt;
}
inline int search(char *str) {
    int len = strlen(str);
    trie *p = root;
    for (int i = 0; i < len; i++) {
        int id = str[i]-'a';
        if (p->next[id] == NULL) return -1;
        p = p->next[id];
    }
    return p->id;
}
int findxy(int x) {
    return x == pre[x] ? pre[x] : findxy(pre[x]);
}
void unit(int x, int y) {
    int nx = findxy(x), ny = findxy(y);
    if (nx == ny) return;
    if (nx > ny) pre[nx] = ny;
    else pre[ny] = nx;
}
int main(int argc, char const *argv[])
{
    char a[20], b[20];
    memset(deg, 0, sizeof deg);
    int cnt = 0;
    for (int i = 1; i < (emax<<1); i++) pre[i] = i;
    while (~scanf("%s %s", a, b)) {
        if (search(a) == -1) insert(a, ++cnt);
        if (search(b) == -1) insert(b, ++cnt);
        int u = search(a), v = search(b);
        deg[u]++, deg[v]++;
        unit(u, v);
    }
    int odd = 0, cut = 0;
    for (int i = 1; i <= cnt; i++) {
        if (deg[i]%2==1) odd++;
        if (pre[i] == i) cut++;
    }
    if ((odd == 0 || odd == 2) && (cut == 0 || cut == 1)) puts("Possible");
    else puts("Impossible");
    return 0;
}
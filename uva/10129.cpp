#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int pre[30];
int findPre(int x) {
    return x == pre[x] ? x : findPre(pre[x]);
}
inline void unin(int x, int y) {
    int fx = findPre(x), fy = findPre(y);
    if (fx == fy) return ;
    if (fx > fy) pre[fx] = fy;
    else pre[fy] = fx;
}
int main(int argc, char const *argv[])
{
    int T, n, cnt;
    char word[1005];
    scanf("%d", &T);
    int in[30], out[30], vis[30];
    while (T--) {
        scanf("%d", &n);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 30; i++) pre[i] = i;
        cnt = 26;
        for (int i = 0; i < n; i++) {
            scanf("%s", word);
            int f = word[0]-'a', s = word[strlen(word)-1]-'a';
            out[f]++;
            in[s]++;
            vis[f] = vis[s] = 1;
            if (findPre(f) != findPre(s)) {
                unin(s, f);
                cnt--;
            }
        }
        int num = 0;
        vector<int> v;
        for (int i = 0; i < 26; i++) {
            if (!vis[i]) cnt--;
            else if (in[i] != out[i]) v.push_back(in[i]-out[i]);
        }
        bool ok = false;
        if (cnt == 1 && (v.empty() || (v.size() == 2 && (v[0] == 1 || v[0] == -1)))) ok = true;
        puts(ok ? "Ordering is possible." : "The door cannot be opened.");
    }
    return 0;
}
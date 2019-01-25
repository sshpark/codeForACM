#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1005;
const int N = 1000005;
char e[maxn][maxn];
int pre[N], bomb[N], cont[N];
int n;

int fd(int x) {
    return x == pre[x] ? x : pre[x] = fd(pre[x]);
}

int getsum(int x, int y) {
    int cnt = 1;
    int sum = 0;
    while (true) {
        int tmp = y-cnt;
        if (tmp < 0) break;

        if (e[x][tmp] == 'E') sum++;
        if (e[x][tmp] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = y+cnt;
        if (tmp >= n) break;

        if (e[x][tmp] == 'E') sum++;
        if (e[x][tmp] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = x-cnt;
        if (tmp < 0) break;

        if (e[tmp][y] == 'E') sum++;
        if (e[tmp][y] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = x+cnt;
        if (tmp >= n) break;

        if (e[tmp][y] == 'E') sum++;
        if (e[tmp][y] == '#') break;
        cnt++;
    }
    return sum;
}

void solve(int x, int y) {
    int cnt = 1;
    int sum = 0;
    vector<int> ans;

    while (true) {
        int tmp = y-cnt;
        if (tmp < 0) break;

        if (e[x][tmp] == 'E') sum++;
        if (e[x][tmp] == 'B') {
            ans.push_back(x*n+tmp);
        }
        if (e[x][tmp] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = y+cnt;
        if (tmp >= n) break;

        if (e[x][tmp] == 'E') sum++;
        if (e[x][tmp] == 'B') {
            ans.push_back(x*n+tmp);
        }
        if (e[x][tmp] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = x-cnt;
        if (tmp < 0) break;

        if (e[tmp][y] == 'E') sum++;
        if (e[tmp][y] == 'B') {
            ans.push_back(tmp*n+y);
        }
        if (e[tmp][y] == '#') break;
        cnt++;
    }
    cnt = 1;
    while (true) {
        int tmp = x+cnt;
        if (tmp >= n) break;

        if (e[tmp][y] == 'E') sum++;
        if (e[tmp][y] == 'B') {
            ans.push_back(tmp*n+y);
        }
        if (e[tmp][y] == '#') break;
        cnt++;
    }
    int fx = fd(x*n+y);
    for (auto val : ans) {
        int fy = fd(val);
        if (fx != fy) {
            pre[fy] = fx;
            cont[fx] += cont[fy];
        }
    }
    
}
int main(int argc, char const *argv[])
{   
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", e[i]);
    for (int i = 0; i < 1000005; i++) {
        bomb[i] = 0;
        cont[i] = 0;
        pre[i] = i;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (e[i][j] == 'B') {
                cont[i*n+j] = getsum(i, j);
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (e[i][j] == 'B')
                solve(i, j);

    int maxa = -1;
    for (int i = 0; i < n*n; i++)
        if (pre[i] == i) maxa = max(cont[i], maxa);
    printf("%d\n", maxa);
    return 0;
}
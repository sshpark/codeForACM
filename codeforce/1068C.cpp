#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
vector<int> p[105];
int main(int argc, char const *argv[])
{
    int n, m, x, y;
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < 105; i++) p[i].clear();
        int col = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            p[x].push_back(col);
            p[y].push_back(col);
            col++;
        }
        for (int i = 1; i <= n; i++) {
            if (p[i].size() == 0) {
                p[i].push_back(col++);
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d\n", (int)p[i].size());
            for (int it : p[i]) {
                printf("%d %d\n", i, it);
            }
        }
    }
    return 0;
}

![](http://sshpark.oss-cn-shenzhen.aliyuncs.com/12326324,2560,1600.jpg =1100x700)
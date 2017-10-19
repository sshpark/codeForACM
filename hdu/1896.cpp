#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
struct node {
    int p;
    int d;
    friend bool operator < (node a, node b) {
        if (a.p == b.p) return a.d > b.d;
        return a.p > b.p;
    }
};
int main(int argc, char const *argv[])
{
    int n, T;
    priority_queue<node> q;
    node x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d", &x.p, &x.d);
            q.push(x);
        }
        int l = 0, maxa = 0;
        while (!q.empty()) {
            x = q.top();
            q.pop();
            l++;
            if (l&1) {
                maxa = max(x.p+x.d, maxa);
                x.p += x.d;
                q.push(x);
            }
        }
        printf("%d\n", maxa);
    }
    return 0;
}
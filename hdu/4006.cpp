#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
struct node {
    int x;
    friend bool operator < (node a,node b) {
        return a.x > b.x;
    }
};
int main(int argc, char const *argv[])
{
    int n, k;
    while (~scanf("%d %d", &n, &k)) {
        priority_queue<node> q;
        int cnt = 0;
        node x;
        while (n--) {
            char op[5];
            scanf("%s", op);
            if (op[0] == 'I') {
                if (cnt < k) {
                    cnt++;
                    scanf("%d", &x.x);
                    q.push(x);
                }
                else {
                    scanf("%d", &x.x);
                    if (x.x > q.top().x) {
                        q.pop();
                        q.push(x);
                    }
                }
            }
            else {
                printf("%d\n", q.top().x);
            }
        }
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
struct node {
    int id;
    int x;
    int t;
    friend bool operator < (node a, node b) {
        if (a.x == b.x) return a.t > b.t;
        return a.x < b.x;
    }
};
int main(int argc, char const *argv[])
{
    int n, f, id;
    node s;
    char op[10];
    while(~scanf("%d", &n)) {
        priority_queue<node> A, B, C;
        id = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%s", op);
            if (op[0] == 'I') {
                scanf("%d %d", &f, &s.x);
                s.t = i;
                s.id = id;
                if (f == 1) A.push(s);
                else if (f == 2) B.push(s);
                else C.push(s);
                id++;
            }
            else {
                scanf("%d", &f);
                if (f == 1) {
                    if (A.empty()) puts("EMPTY");
                    else printf("%d\n", A.top().id), A.pop();                    
                }
                else if (f == 2) {
                    if (B.empty()) puts("EMPTY");
                    else printf("%d\n", B.top().id), B.pop();                    
                }
                else {
                    if (C.empty()) puts("EMPTY");
                    else printf("%d\n", C.top().id), C.pop();                    
                }
            }
        }
    }
    return 0;
}
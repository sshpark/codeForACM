#include <iostream>
#include <algorithm>
using namespace std;
int top;
long long maxa;
struct node {
    long long v;
    int l, r;
}st[100005];
inline void push(node x) {
    while (top > 0 && x.v <= st[top].v) {
        x.l = st[top].l;
        st[top-1].r = st[top].r;
        maxa = max(maxa, st[top].v*(st[top].r-st[top].l + 1));
        top--;
    }
    st[++top] = x;
}
int main(int argc, char const *argv[])
{
    int n;
    node x;
    while (~scanf("%d", &n) && n) {
        top = 0;
        maxa = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x.v);
            x.l = x.r = i;
            push(x);
        }
        while (top) {
            st[top-1].r = st[top].r;
            maxa = max(maxa, st[top].v*(st[top].r-st[top].l+1));
            top--;
        }
        printf("%lld\n", maxa);
    }
    return 0;
}
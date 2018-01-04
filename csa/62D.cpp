#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
int top = 0;
struct node {
    ll w;
    int l;
}a[maxn], b[maxn];
node st[maxn];
int cnt[maxn];
inline void push(node& x) {
    while (top > 0 && x.w > st[top].w) {
        x.l = st[top].l;
        top--;
    }
    st[++top] = x;
}
int main(int argc, char const *argv[])
{
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].w;
        a[i].l = i;
        push(a[i]);
    }
    for (int i = 0; i < n; i++) 
        if (a[i].l > 0)
            cnt[a[i].l-1]++;
    int maxa = 0, pos = 0;
    for (int i = 0; i < maxn; i++)
        if (cnt[i] > maxa) {
            maxa = cnt[i];
            pos = i;
        }
    int num = 0;
    top = 0;
    for (int i = 0; i < n; i++)
        if (i != pos) {
            b[num].w = a[i].w;
            b[num].l = num;
            push(b[num]);
            num++;
        }
    int ans = 0;
    for (int i = 0; i < num; i++)
        if (b[i].l == 0) ans++;
    printf("%d\n", ans);

    return 0;
}
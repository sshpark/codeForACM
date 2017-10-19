#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define inf 2147483647
const int maxn = 1000005;
int n, k;
int a[maxn];
struct node
{
    int val;
    int index;
}que[maxn];
inline void getMin() {
    memset(que, 0, sizeof que);
    int head = 1, tail = 1;
    for (int i = 1; i <= k; i++) {
        while (que[tail].val >= a[i] && tail >= head) tail--;
        que[++tail].val = a[i];
        que[tail].index = i;
    }
    for (int i = k; i <= n; i++) {
        while (que[tail].val >= a[i] && tail >= head) tail--;
        que[++tail].val = a[i];
        que[tail].index = i;
        while (que[head].index <= i-k) head++;
        printf("%d ", que[head].val);
    }
}
inline void getMax() {
    memset(que, 0, sizeof que);
    int head = 1, tail = 1;
    for (int i = 1; i <= k; i++) {
        while (que[tail].val <= a[i] && tail >= head) tail--;
        que[++tail].val = a[i];
        que[tail].index = i;
    }
    for (int i = k; i <= n; i++) {
        while (que[tail].val <= a[i] && tail >= head) tail--;
        que[++tail].val = a[i];
        que[tail].index = i;
        while (que[head].index <= i-k) head++;
        printf("%d ", que[head].val);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    getMin();
    puts("");
    getMax();
    return 0;
}
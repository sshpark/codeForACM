#include <iostream>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
struct node {
    int val;
    int cnt;
};
int main(int argc, char const *argv[])
{
    int n;
    node a[505];
    ll k, cur = 0;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].val);
        a[i].cnt = 0;
    }
    if (k > (ll)n) {
        printf("%d\n", n);
        return 0;
    }
    int j = 2;
    while (true) {
        if (a[1].val > a[2].val) {
            a[1].cnt++;
            if (a[1].cnt == k) {
                printf("%d\n", a[1].val);
                return 0;
            }
            int tem = a[2].val, tem1 = a[2].cnt;
            for (int i = 2; i < n; i++) {
                a[i].val = a[i+1].val;
                a[i].cnt = a[i+1].cnt;
            }
            a[n].val = tem, a[n].cnt = tem1;
        }
        else {
            a[2].cnt++;
            if (a[2].cnt == k) {
                printf("%d\n", a[2].val);
                return 0;
            }
            int tem = a[1].val, tem1 = a[1].cnt;
            for (int i = 1; i < n; i++) {
                a[i].val = a[i+1].val;
                a[i].cnt = a[i+1].cnt;
            }
            a[n].val = tem, a[n].cnt = tem1;
        }
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;
#define ll long long
int a[1000005];
struct node {
    int x;
    friend bool operator < (node a,node b) {
        return a.x < b.x;
    }
};
priority_queue<node> q;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    node x;
    for (int i = 0; i < n; i++) {
        x.x = i;
        q.push(x);
        int k = i-a[i] >= 0 ? i-a[i] : 0;
        while (q.top().x > k && !q.empty()) {
            q.pop();
        }
    }
    printf("%d\n", (int)q.size());
    return 0;
}
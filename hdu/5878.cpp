#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int p[4] = {2, 3, 5, 7};
priority_queue<ll, vector<ll>, greater<ll> > pq;
set<ll> s;
vector<ll> v;

int main(int argc, char const *argv[])
{
    pq.push(1);
    s.insert(1);
    while (true) {
        ll top = pq.top(); pq.pop();
        if (top > 1e9) break;
        for (int i = 0; i < 4; i++) {
            ll x = top*p[i];
            if (s.count(x) == 0) {
                pq.push(x);
                s.insert(x);
            }
        }
    }
    for (auto it : s) v.push_back(it);
    int T;
    ll x;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &x);
        if (s.count(x)) printf("%lld\n", x);
        else printf("%lld\n", *(upper_bound(v.begin(), v.end(), x)));
    }
    return 0;
}
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define ll long long
deque<pair<int, int> > q;
int main(int argc, char const *argv[])
{
    int n, a, b;
    while (~scanf("%d %d %d", &n, &a, &b)) {
        q.clear();        
        ll sum = 1, x = 1;
        for (int i = 1; i <=n; i++) {
            x = x*a%b;
            while (!q.empty() && q.front().first < i-a) q.pop_front();
            while (!q.empty() && q.front().second >= x) q.pop_back();
            q.push_back(make_pair(i, x));
            sum = sum*q.front().second%b;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
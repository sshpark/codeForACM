#include <iostream>
#include <set>
using namespace std;
const int maxn = 100005;
int n, l, r, low;
int d[maxn], a[maxn];
long long m, sum, f[maxn], tem;
multiset<int> tree;
int main(int argc, char const *argv[])
{
    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    l = 0, r = -1, sum = 0, low = 1;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while (sum > m) sum -=a[low++];
        if (low > i) {
            l = 0;r = -1;printf("-1");flag=false;break;
        }
        while (l <= r && a[i] >= a[d[r]]) {
            if (r > l) tree.erase(f[d[r-1]]+a[d[r]]);
            r--;
        }
        d[++r]=i;
        if (r>l) tree.insert(f[d[r-1]]+a[d[r]]);
            while (low>d[l]) {
                if (r>l) tree.erase(f[d[l]]+a[d[l+1]]);
                l++;
            }
        tem=*(tree.begin());
        f[i]=f[low-1]+a[d[l]];
        if (l<r && tem < f[i]) f[i]=tem;
    }
    if (flag) printf("%lld\n",f[n]);
    return 0;
}
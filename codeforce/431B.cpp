#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[1005], tem[1005], cnt, flag = 0, flag1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    for (int i = 3; i <= n; i++)
        if (a[i]-a[i-1] != a[i-1]-a[i-2]) {
            flag = 1;
            break;
        }
    if (flag) {
        set<int> s;
        bool ok = true;
        for (int i = 2; i <= n; i++) {
            ok = true;
            s.clear();
            double d = (double)(a[i] - a[1])/(i-1);
            for (int j = 2; j <= n; j++)
                if ((double)(a[j] - a[1])/(j-1) == d) s.insert(j);
            cnt = 0;
            for (int j = 2; j <= n; j++)
                if (s.count(j) == 0) tem[++cnt] = j;
            for (int j = 2; j <= cnt; j++)
                if ((double)(a[tem[j]]-a[tem[j-1]])/(tem[j]-tem[j-1]) != d) {
                    ok = false;
                    break;
                }
            if (ok && (cnt + (int)s.size() == n-1)) {
                puts("Yes");
                return 0;
            }
        }
        double k=(a[3]-a[2])*1.0;
        for(int i = 4;i <= n; i++)
        {
            if((a[i]-a[2])*1.0/(i-2)!=k)
            {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
    else
        puts("No");
    return 0;
}
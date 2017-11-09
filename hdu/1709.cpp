#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, num[105];
    int a[10005], b[10005];
    while (~scanf("%d", &n)) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", num+i);
            sum += num[i];
        }
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b); 
        a[0] = a[num[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++)
                for (int k = 0; k <= num[i]; k += num[i]) {
                    b[k+j] += a[j];
                    b[(j - k) > 0 ? j - k : k - j] += a[j];
                }
            for (int j = 0; j <= sum; j++) {
                a[j] = b[j];
                b[j] = 0;
            }
        }
        vector<int> v;
        for (int i = 1; i <= sum; i++)
            if (!a[i]) v.push_back(i);
        int len = (int)v.size();
        printf("%d\n", len);
        for (int i = 0; i < len; i++)
            if (i != 0) printf(" %d", v[i]);
            else printf("%d", v[i]);
        printf(len ? "\n" : "");
    }
    return 0;
}
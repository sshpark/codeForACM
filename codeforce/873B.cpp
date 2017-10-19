#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    char str[100005];
    int a[100005];
    scanf("%d %s", &n, str+1);
    for (int i = 0; i < n; i++)
        if (str[i] == '0') a[i] = -1;
        else a[i] = 1;
    int sum = 0, ans = 0;
    map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (m[sum]) ans = max(ans, i-m[sum]);
        else m[sum] = i;
    }
    printf("%d\n", ans);
    return 0;
}
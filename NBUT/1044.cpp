#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, a[2005];
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n; i < m+n; i++) cin >> a[i];
        sort(a, a+m+n);
        printf("%d", a[0]);
        for (int i = 1; i < m+n; ++i) printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}
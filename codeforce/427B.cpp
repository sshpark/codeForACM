#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, c, t, x;
    int ans = 0, now = 0;
    scanf("%d %d %d", &n, &t, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x <= t) {
            now++;
            if (now >= c) ans++;
        }
        else now = 0;
    }
    printf("%d\n", ans);
    return 0;
}
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[10005];
    bool flag = false;
    scanf("%d", &n);
    int cur = 0, maxa = -0xfffff;
    int st = 0, ed = n-1;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        if (a[i] >= 0) flag = true;
    }
    if (!flag) {
        for (int i = 0; i < n; i++)
            if (maxa < a[i]) {
                maxa = a[i];
                st = i;
            }
        printf("0 %d %d\n", a[0], a[n-1]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cur += a[i];
        if (maxa < cur) {
            ed = i;
            maxa = cur;
        }
        if (cur < 0)
            cur = 0;
             
    }
    int _maxa = maxa;
    for (int i = ed; ; i--) {
        _maxa -= a[i];
        if (_maxa == 0) {
            st = i;
            break;
        }
    }
    printf("%d %d %d\n", maxa, a[st], a[ed]);
   return 0;
}
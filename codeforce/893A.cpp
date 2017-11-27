#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[105], u = 1, v = 2, s = 3;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] != u && a[i] != v) {
            puts("NO");
            return 0;
        }
        if (a[i] == u) {
            int t = v;
            u = a[i];
            v = s;
            s = t;
        } else {
            int t = u;
            u = a[i];
            v = s;
            s = t;
        }
    }
    puts("YES");
    return 0;
}
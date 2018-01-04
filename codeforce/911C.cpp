#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
inline bool ok(int a, int b, int c) {
    if (a == 1 || b == 1 || c == 1) return true;
    if ((a == 2 && b == 2) || (b == 2 && c == 2) || (a == 2 && c == 2)) return true;
    if (a == 3 && b == 3 && c == 3) return true;
    if ((a==2&&b==4&&c==4) || (b==2&&a==4&&c==4) || (c==2&&a==4&&b==4)) return true;
    return false;
}
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    puts(ok(a, b, c) ? "YES" : "NO");
    return 0;
}
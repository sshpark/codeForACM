#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, m, a, b;
    cin >> n >> m;
    double mina = 1000000000;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        mina = min(mina, a*1.0/b);
    }
    printf("%.8lf\n", mina*m);
    return 0;
}
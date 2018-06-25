#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <set>
using namespace std;
#define ll long long
set<double> s;
int main(int argc, char const *argv[])
{
    int n, m, a, b;
    cin >> m >> n >> a >> b;
    for (int i = a; i < a+n; i++)
        for (int j = b; j < b+m; j++) {
            double x = (double)j*log2(1.0*i);
            s.insert(x);
        }
    printf("%lu\n", s.size());
    return 0;
}
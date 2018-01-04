#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
vector<int> v;
int main(int argc, char const *argv[])
{
    int n, f, s;
    f = s = 0;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        if (f <= s) {
            f += i;
            v.push_back(i);
        } else s += i;
    }
    printf("%d\n", abs(f-s));
    printf("%d ", (int)v.size());
    for (auto i : v) printf("%d ", i);
    return 0;
}
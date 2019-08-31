#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/codeforce/1.in", "r", stdin);
    
    int n, l, r;
    cin >> n >> l >> r;
    int mina = (n-l+1)+(1<<l)-2;
    int maxa = ((1<<r)-1)+(n-r)*(1<<(r-1));
    cout << mina << " " << maxa << endl;

    return 0;
}
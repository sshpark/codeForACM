#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    double fen = (n-r+1)*(m-r+1);
    double sum = fen*(k-r+1)+(k-r-1);
    printf("%.9lf\n", sum/fen);
    return 0;
}
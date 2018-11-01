#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, a, b, maxa = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        maxa = max(a+b, maxa);
    }
    cout << maxa << endl;

    return 0;
}
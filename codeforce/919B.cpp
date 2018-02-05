#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
inline bool ok(int n) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum == 10;
}
int main(int argc, char const *argv[])
{
    int k, cnt = 0;
    cin >> k;
    for (int i = 0; ; i++) {
        if (ok(i)) {
            cnt++;
            if (cnt == k) {
                return 0*printf("%d\n", i);
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long bit[20], n, index = 0, a[20], cnt = 0, nxt;
    bit[0] = 0;
    for (int i = 1; i < 19; i++) bit[i] = 9*i*pow(10, i-1);
    cin >> n;
    if (n == 0) return 0*puts("0");
    while (n > bit[index]) n -= bit[index++];
    nxt = pow(10, index-1)+n/index-1;
    if (n % index) {
        nxt++;
        while (nxt) a[cnt++] = nxt%10, nxt /= 10;
        cout << a[cnt-n%index] << endl;
    } else cout << nxt%10 << endl;
    return 0;
}
#include <iostream>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;
    int c = 1;
    if (b - a >= 10) {
        puts("0");
        return 0;
    }
    for (ll i = a+1; i <= b; i++)
        c = c*i%10;
    printf("%d\n", c);
    return 0;
}
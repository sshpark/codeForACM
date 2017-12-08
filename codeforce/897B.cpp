#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long long k, p, s = 0;
    scanf("%lld %lld", &k, &p);
    for (register int i = 1; i <= k; ++i)
    {
        long long tmp=i,tpp=i;
        for (; tmp; tpp=(tpp*10+tmp%10),tmp/=10);
        s = (s+tpp%p)%p;
    }
    printf("%lld\n", s);
}
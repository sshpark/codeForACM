#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    double r;
    const double PI = 3.1415927;
    while (~scanf("%lf", &r)) {
        printf("%.3lf\n", PI*r*r*r*4/3);
    }
    return 0;
}
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    while(cin >> x) {
        printf("%d\n", x|3^2|1|3&12);
    }
    return 0;
}
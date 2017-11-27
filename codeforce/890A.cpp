#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int main(int argc, char const *argv[])
{
    srand(unsigned(time(NULL)));
    int a[10];
    scanf("%d %d %d %d %d %d", a, a+1, a+2, a+3, a+4, a+5);
    for (int i = 0; i < 100; i++) {
        random_shuffle(a, a+6);
        if (a[0]+a[1]+a[2] == a[3]+a[4]+a[5]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
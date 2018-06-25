#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int s = sqrt(100);
    int guess_number, round = 10;
    srand((unsigned)time(NULL));

    int result = rand()%1000+1;
    int ok = 0;

    while (round--) {
        scanf("%d", &guess_number);
        if (guess_number == result) {
            ok = 1;
            break;
        } else if (guess_number > result) {
            puts("大了");
        } else {
            puts("小了");
        }
    }
    puts(ok ? "猜对了" : "猜数失败");
    return 0;
}
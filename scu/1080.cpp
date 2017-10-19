#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, l, a, x, y, z, kill;
    char monster[15];
    while (~scanf("%d %d %d", &n, &l, &a) && n+l+a) {
        bool flag = true;
        while (n--) {
            scanf("%s %d %d %d", monster, &x, &y, &z);
            if (monster[0] == 'Z') {
                if (l >= x*3) {
                    l -= x*3;
                    l += y*9;
                    a += z*4;
                }
                else {
                    x = x - l/3;
                    l = l%3;
                    a -= x;
                    if (a <= 0)
                        flag = false;
                }
            }
            else if (monster[0] == 'C') {
                if (l >= x*4) {
                    l -= x*4;
                    l += y*9;
                    a += z*4;
                }
                else {
                    x = x - l/4;
                    l = l%4;
                    a -= x;
                    if (a <= 0)
                        flag = false;
                }
            }
            else if (monster[0] == 'S') {
                if (l >= x*5) {
                    l -= x*5;
                    l += y*9;
                    a += z*4;
                }
                else {
                    x = x - l/5;
                    l = l%5;
                    a -= 2*x;
                    if (a <= 0)
                        flag = false;
                }
            }
            else if (monster[0] == 'L') {
                if (l >= x*6) {
                    l -= x*6;
                    l += y*9;
                    a += z*4;
                }
                else {
                    x = x - l/6;
                    l = l%6;
                    a -= 3*x;
                    if (a <= 0)
                        flag = false;
                }
            }
            else if (monster[0] == 'N') {
                if (l >= x*20) {
                    l -= x*20;
                }
                else {
                    x = x - l/20;
                    l = l%20;
                    a -= 4*x;
                    if (a <= 0)
                        flag = false;
                }   
            }
            else {
                if (l >= x*15) {
                    l -= x*15;
                    l += y*9;
                    a += z*4;
                }
                else {
                    x = x - l/15;
                    l = l%15;
                    a -= 4*x;
                    if (a <= 0)
                        flag = false;
                }
            }
        }
        puts(flag ? "You can survive in the last escape." : "You are gonna die down here.");
    }
    return 0;
}
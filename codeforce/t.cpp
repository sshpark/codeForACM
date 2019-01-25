#include <iostream>
#include<stdlib.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define REVERSE(q) ((((q) >> 24) & 0xff) + (((q) >> 8) & 0xff00) + (((q) & 0xff00) << 8) + (((q) & 0xff) << 24)) 
unsigned long func(unsigned long v)
{   unsigned long t;
    t = v ^ ((v << 16) | (v >> 16));  
    t &= 0xff00ffff;
    v = (v << 24) | (v >> 8);   
    return v ^ (t >> 8);       
}
void display_binary(unsigned long x) {
    int ans[40];
    memset(ans, 0, sizeof ans);
    int cnt = 0;
    while (x) {
        if (x&1) ans[cnt++] = 1;
        else ans[cnt++] = 0;
        x >>= 1;
    }

    for (int i = 31; i >= 0; i--) {
        if ((i+1)%8 == 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsigned int t = 0x89ABCDEF;
    // printf("%X %X\n", t, swap32Big2Little(t));
    // display_binary(t);
    // display_binary(v);
    
    return 0;
}
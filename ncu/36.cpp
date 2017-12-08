#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
char post[10], mid[10];
void PostMidCreateTree(int root, int start, int end) {
    if (start > end) return;
    int m = start;
    while (m < end && mid[m] != post[root]) m++;
    printf("%c", mid[m]);
    PostMidCreateTree(root-1-(end-m), start, m-1);
    PostMidCreateTree(root-1, m+1, end);
}

int main(int argc, char const *argv[])
{
    scanf("%s %s", mid, post);
    PostMidCreateTree(strlen(post)-1, 0, strlen(post)-1);
    printf("\n");
    return 0;
}
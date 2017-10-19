#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<cstdlib>
using namespace std;
struct node {
    int val;
    struct node *l, *r;
};
node *root;
node *insert(node *rt, int x) {
    if (rt == NULL) {
        rt = (node *)malloc(sizeof(node));
        rt -> val = x;
        rt -> l = rt -> r = NULL;
        return rt;
    }
    if (rt -> val > x)
        rt->l = insert(rt->l, x);
    else
        rt->r = insert(rt->r, x);
    return rt;
}
void printTree(node *rt, int x) {
    if (x == 1)
        printf("%d",rt->val);
    else
        printf(" %d",rt->val);
    if (rt->l != NULL)
        printTree(rt->l, 2);
    if (rt->r != NULL)
        printTree(rt->r, 2);
}
int  main(int argc, char const *argv[])
{
    int n, x;
    while (~scanf("%d", &n)) {
        root = NULL;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            root = insert(root, x);
        }
        printTree(root, 1);
    }
    printf("\n");
    return 0;
}
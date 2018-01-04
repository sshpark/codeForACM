#include <string.h>  
#include <algorithm>  
#include <stdio.h>  
#include <math.h>  
#include <queue>  
#define MAXN 100010  
#define inf 0x3f3f3f3f  
  
using namespace std;  
  
struct node{  
    int l,r;//区间[l,r]  
    int add;//区间的延时标记  
    int mx; //区间最大值  
}tree[MAXN<<2];//一定要开到4倍多的空间  
  
void pushup(int index){  
    tree[index].mx = max(tree[index<<1].mx,tree[index<<1|1].mx);  
}  
void pushdown(int index){  
    if(tree[index].add > 0){
        tree[index<<1].mx += tree[index].add;  
        tree[index<<1|1].mx += tree[index].add;  
        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;
    }  
}  
void build(int l,int r,int index){  
    tree[index].l = l;  
    tree[index].r = r;  
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){  
        tree[index].mx = 0;
        return ;  
    }  
    int mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}  
void updata(int l,int r,int index,int val){  
    if(l <= tree[index].l && r >= tree[index].r){  
        tree[index].mx += val;  
        tree[index].add += val;
        return ;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,index<<1,val);  
    }  
    if(r > mid){  
        updata(l,r,index<<1|1,val);  
    }  
    pushup(index);  
}  
int query(int l,int r,int index){  
    if(l <= tree[index].l && r >= tree[index].r){  
        return tree[index].mx;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    int Max = 0;  
    if(l <= mid){  
        Max = max(query(l,r,index<<1),Max);  
    }  
    if(r > mid){  
        Max = max(query(l,r,index<<1|1),Max);
    }  
    return Max;  
}  
int main()  
{  
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    int n,x,y,ans;  
    scanf("%d", &n);
    build(1,100000,1);
    while(n--){  
        scanf("%d %d",&x, &y);
        ans = query(x,y,1);
        printf("%d\n", ans+1);
        updata(x,y,1,1);
    }
    return 0;  
}
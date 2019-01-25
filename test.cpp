#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define max(x,y) (((x)>(y))?(x):(y))
using namespace std;
int n,top;
struct point
{
    double x,y;
}p[50000+16],stack[10000];
bool equal(double n)
{
    return fabs(n-0)<eps;
}
double cp(const point p1,const point p2,const point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(const point p1,const point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp(const point p1,const point p2)
{
    double res=cp(p1,p2,p[0]);
    if(equal(res))
        return dis(p[0],p1)-dis(p[0],p2)<=0;
    else
        return res>0;
}
double rotate_calipers(int num)
{
    int p=1,q=2,i;
    double ans=0;
    stack[++num]=stack[0];
    for(i=0;i<num;i++)
    {
        while(cp(stack[i],stack[p],stack[q+1])>cp(stack[i],stack[p],stack[q]))
            q=(q+1)%num;
        ans=max(ans,cp(stack[i],stack[p],stack[q])/2.0);
        while(cp(stack[i],stack[p+1],stack[q])>cp(stack[i],stack[p],stack[q]))
            p=(p+1)%num;
        ans=max(ans,cp(stack[i],stack[p],stack[q])/2.0);
    }
    return ans;
}
int main()
{
    int i,pos;
    double res=0;
    while(~scanf("%d",&n))
    {
        if(n==-1)
            break;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        pos=0;
        for(i=1;i<n;i++)
        {
            if(p[pos].y>=p[i].y)
            {
                if(p[pos].y==p[i].y)
                {
                    if(p[pos].x>p[i].x)
                        pos=i;
                }
                else
                    pos=i;
            }
        }
        point temp;
        temp=p[pos];
        p[pos]=p[0];
        p[0]=temp;
        sort(p+1,p+n,cmp);
        top=1;
        stack[0]=p[0];
        stack[1]=p[1];
        for(i=2;i<n;i++)
        {
            while(cp(stack[top],p[i],stack[top-1])<0)
                top--;
            stack[++top]=p[i];
        }
        printf("%.2lf\n",rotate_calipers(top));
    }
    return 0;
}
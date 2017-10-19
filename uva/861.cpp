//
//2012/2/28
//
//
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXSIZE 8
void backtrack(int m,int row,int col);
int a[8][8];//初始化为0，做为标记位
int n,k;
long long sum;
int main()
{
    while(true)
    {
        cin>>n>>k;
        if(n==0 && k==0) break;
        
        memset(a,0,sizeof(a));
        sum=0;//记录解的个数
        //回溯法找合适的解
        backtrack(0,0,0);
        cout<<sum<<endl;
    }
    return 0;
}
bool issolution(int i,int j)
{
    //判断i,j位置上是否可以放象，
    //检查i,j位置是左上角对角线和右上角对角线，下面的不用检查
    int t=1;
    while(i-t>=0 && j-t>=0)
    {
        if(a[i-t][j-t]==1) return false;
        t++;
    }
    t=1;
    while(i-t>=0 && j+t<n)
    {
        if(a[i-t][j+t]==1) return false;
        t++;
    }
    return true;
}
void print()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<"######"<<endl;
}
void backtrack(int m,int row,int col)
{
//如果m为k时，sum++,否则继续寻找合适的解
    if(m==k)
    {
        ++sum;
        //print();
    }//剪去剩余量+m不能满足==k的分支
    else if(n*n-n*row-col< k-m) return;
    else
    {
        //保证从第i,j个开始寻找
        int j;
        j=col;
        for(int i=row;i<n;++i)
        {
            for(;j<n;j++)
            {
                
                if(a[i][j]!=1 && issolution(i,j))
                {
                    a[i][j]=1;
                    if(j==n-1)
                        backtrack(m+1,i+1,0);
                    else
                       backtrack(m+1,i,j+1);
                    a[i][j]=0;
                }
            }
            j=0;
        }
    }
}
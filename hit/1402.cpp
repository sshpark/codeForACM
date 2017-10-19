#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXSIZE 8
void backtrack(int m,int row,int col);
int a[8][8];
int n,k;
long long sum;
int main()
{
    while(true)
    {
        cin>>n>>k;
        if(n==0 && k==0) break;
        
        memset(a,0,sizeof(a));
        sum=0;
        backtrack(0,0,0);
        cout<<sum<<endl;
    }
    return 0;
}
bool issolution(int i,int j)
{
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
    if(m==k)
        ++sum;
    else if(n*n-n*row-col< k-m) return;
    else
    {
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
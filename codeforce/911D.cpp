#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int n, m, ans, a[1505], tmp[1505], b[1505];
void Merge(int l,int m,int r)  
{  
    int i = l;  
    int j = m + 1;  
    int k = l;  
    while(i <= m && j <= r)  
    {  
        if(a[i] > a[j])  
        {  
            tmp[k++] = a[j++];  
            ans += m - i + 1;  
        }  
        else  
        {  
            tmp[k++] = a[i++];  
        }  
    }  
    while(i <= m) tmp[k++] = a[i++];  
    while(j <= r) tmp[k++] = a[j++];  
    for(int i=l;i<=r;i++)  
        a[i] = tmp[i];  
}  
  
void Merge_sort(int l,int r)  
{  
    if(l < r)  
    {  
        int m = (l + r) >> 1;  
        Merge_sort(l,m);  
        Merge_sort(m+1,r);  
        Merge(l,m,r);  
    }  
}

int main(int argc, char const *argv[])
{
    int l, r;
    string re;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        b[i] = a[i];
    }
    scanf("%d", &m);
    ans = 0;
    Merge_sort(0, n-1);
    if (ans&1) re = "odd";
    else re = "even";
    int temp = 0;
    while(m--) {
        scanf("%d %d", &l, &r);
        temp += (r-l+1)/2;
        if (temp%2 == 0) {
            cout << re << endl;
        } else {
            if (re == "odd") cout << "even" << endl;
            else cout << "odd" << endl;
        }
    }
    return 0;
}
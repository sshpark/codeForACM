#include<stdio.h>  
#include<string>  
#include<algorithm>
#include<iostream> 
using namespace std;
char s[1005];  
int main()  
{   
    int t,i,j,Min,p=1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        Min=1000000000;
        scanf("%s",s);  
        for(i=0;s[i]!='\0';i++)  
            for(j=i+1;s[j]!='\0';j++)  
                if(s[i]==s[j])  
                    Min=min(Min,j-i);  
        printf("Case #%d: ",p++);                      
        if(Min!=1000000000)  
            printf("%d\n",Min);  
        else  
            puts("-1");  
    }  
    return 0;   
} 
#include <iostream>
#include <set>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
using namespace std;
const int N = 1000055;
char s1[N], s2[N];
int nex[N], len1, len2;
void get_nex()
{
    nex[0] = 0;
    for(int i = 1; i < len2; i++)
    {
        int j = nex[i-1];
        while(j && s2[i] != s2[j])
            j = nex[j-1];
        if(s2[i] == s2[j]) nex[i] = j+1;
        else nex[i] = 0;
    }
}
int maxa = 0;
void KMP()
{
    int i = 0, j = 0, ans = 0;
    while(i < len1 && j < len2)
    {
        if(s1[i] == s2[j])
            i++, j++;
        else {
            if(!j) i++;
            else j = nex[j-1];
        }
        if(j == len2)
        {
            ans++;
            j = 0;//核心点，匹配成功后，下标从0开始。
        }
    }
    maxa = max(maxa, ans);
}
int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    len1 = n;
    len2 = k;
    scanf("%s", s1);
    set<string> s;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i+1; j < i+k && j < n; j++) {
            if (s1[j] == s1[j-1]) cnt++;
            else cnt = 1;

            s2[cnt-1] = s1[i];

            if (cnt == k) {
                get_nex();
                KMP();
                i = j;
                break;
            }
            i = j;
        }
    }
    printf("%d\n", maxa);
        
    
    return 0;
}